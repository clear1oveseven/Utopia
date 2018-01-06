 #include "EffectBase.h"
#include "EffectConfigBase.h"
#include <assert.h>
#include "GameLogic/Scene/SceneModule/SceneEffects/SceneEffects.h"
#include "GameLogic/Scene/NewScene.h"
#include "GameLogic/Scene/SceneUnit/SceneUnit.h"
#include "GameLogic/Scene/Skills/Skill.h"
#include "GameLogic/Scene/SceneModule/SceneUnitFilter/SceneUnitFilter.h"
#include "GameLogic/Scene/NewScene.h"
#include "GameLogic/Scene/Effects/EffectFilterConfig.h"
#include "GameLogic/Scene/Config/SceneAllConfig.h"
#include "GameLogic/Scene/SceneUnitModules/SceneUnitTransform.h"

namespace GameLogic
{
	EffectBase::EffectBase(const EffectConfigBase *cfg, SceneEffects *scene_effects, uint64_t effect_key)
	{
		assert(cfg && scene_effects);
		m_base_cfg = cfg;
		assert(m_base_cfg);
		m_effect_key = effect_key;
		m_scene_effects = scene_effects;
		m_scene = scene_effects->GetScene();
	}

	EffectBase::~EffectBase()
	{
		m_user_effect_param.Reset();
	}

	std::shared_ptr<SceneUnit> EffectBase::GetCaster()
	{
		return m_user_effect_param.skill->GetCaster();
	}

	std::shared_ptr<SceneUnit> EffectBase::GetEffectTarget()
	{
		return m_scene->GetUnit(m_user_effect_param.target_suid);
	}

	void EffectBase::Begin(UseEffectParam use_effect_param)
	{
		assert(EEffectStage_Wait == m_stage);
		assert(use_effect_param.skill);
		m_user_effect_param = use_effect_param;
		m_stage = EEffectStage_Begin;
		m_begin_ms = m_scene->GetLogicMs();

		if (this->Reversible())
		{
			m_scene_effects->AddEffect(this->shared_from_this());
		}

		this->OnBegin(m_user_effect_param);
		if (IsDone())
			return;

		for (int effect_id : m_base_cfg->GetBeginEffectIds())
		{
			std::shared_ptr<EffectBase> begin_effect = m_scene_effects->CreateEffect(effect_id);
			assert(begin_effect);
			if (nullptr != begin_effect)
			{
				begin_effect->Begin(m_user_effect_param);
			}
		}
		this->OnLateBegin(m_user_effect_param);
		if (IsDone())
			return;

		if (this->NeedGuide())
		{
			assert(m_user_effect_param.skill);
			m_user_effect_param.skill->AddGuideEffect(this->shared_from_this());
		}
	}

	void EffectBase::End(EEffectEndCase end_case)
	{
		if (EEffectStage_Wait == m_stage || EEffectStage_End == end_case)
			return;

		this->OnEnd(end_case);
		for (EndEffectId item : m_base_cfg->GetEndEffectIds())
		{
			bool will_create = false;
			if (EEffectEndCase_Both == item.end_case)
				will_create = true;
			else if (item.end_case == end_case)
				will_create = true;
			if (!will_create)
				continue;

			std::shared_ptr<EffectBase> end_effect = m_scene_effects->CreateEffect(item.id);
			assert(end_effect);
			if (nullptr != end_effect)
			{
				end_effect->Begin(m_user_effect_param);
			}
		}
		this->OnLateEnd(end_case);
		m_stage = EEffectStage_End;

		m_scene_effects->RemoveEffect(m_effect_key);
		m_user_effect_param.Reset();
	}

	void EffectBase::Loop(int64_t now_ms, int64_t delta_ms)
	{
		if (EEffectStage_Begin != m_stage && EEffectStage_Loop != m_stage)
			return;
		if (EEffectStage_Begin == m_stage)
			m_stage = EEffectStage_Loop;

		if (this->IsDone())
		{
			this->End(EEffectEndCase_Done);
			return;
		}
		this->OnLoop(now_ms, delta_ms);
		if (this->IsDone())
		{
			this->End(EEffectEndCase_Done);
			return;
		}
		this->FireLoopEffects(now_ms - m_begin_ms);
		this->OnLateLoop(now_ms, delta_ms);
		if (this->IsDone())
		{
			this->End(EEffectEndCase_Done);
		}
	}

	bool EffectBase::IsGuiding()
	{
		if (NeedGuide() && (EEffectStage_Begin == m_stage || EEffectStage_Loop == m_stage) &&
			m_next_loop_effect_idx < m_base_cfg->GetLoopEffectIds().effect_ids.size())
			return true;
		return false;
	}

	bool EffectBase::CanCancelGuide()
	{
		if (this->CanCancelGuide())
			return true;
		return !this->IsGuiding();
	}

	bool EffectBase::CanCelGuide(bool is_force)
	{
		if (!is_force && !this->CanCancelGuide())
			return false;
		this->End(EEffectEndCase_Break);
		return true;
	}

	bool EffectBase::NeedGuide()
	{
		if (!this->Reversible())
			return false;
		return m_base_cfg->NeedGuide();
	}

	bool EffectBase::Reversible()
	{
		return m_base_cfg->Reversible();
	}
	bool EffectBase::IsDone()
	{
		return this->IsLoopEffectsDone();
	}

	void EffectBase::FireLoopEffects(int64_t elapse_ms)
	{
		if (this->IsLoopEffectsDone())
			return;

		const TimeLineEffectIdsConfig &cfg = m_base_cfg->GetLoopEffectIds();
		for (size_t idx = m_next_loop_effect_idx; idx < cfg.effect_ids.size(); ++idx)
		{
			const TimeLineEffectId &effect_id = cfg.effect_ids[idx];
			if (elapse_ms >= effect_id.wait_ms)
			{
				++m_next_loop_effect_idx;
				std::shared_ptr<EffectBase> new_effect = m_scene_effects->CreateEffect(effect_id.id);
				new_effect->Begin(m_user_effect_param);
			}
		}
	}

	bool EffectBase::IsLoopEffectsDone()
	{
		const TimeLineEffectIdsConfig &cfg = m_base_cfg->GetLoopEffectIds();
		return m_next_loop_effect_idx >= cfg.effect_ids.size();
	}
	std::unordered_map<uint64_t, std::shared_ptr<SceneUnit>> EffectBase::FilterSceneUnits()
	{
		SceneUnitFilter *su_filter = m_scene->GetModule<SceneUnitFilter>();
		const EffectFilterConfig *filter_cfg = m_scene->GetCfg()->effect_filter_cfg_mgr->GetCfg(m_base_cfg->GetFilterId());
		assert(filter_cfg);

		std::shared_ptr<SceneUnit> caster = this->GetCaster();
		EffectFilterShape shape;
		shape.shape = filter_cfg->shape;
		shape.shape_param = filter_cfg->shape_param;
		
		// todo
		switch (filter_cfg->anchor)
		{
			case EEffectAnchor_Pos:
			{
				shape.pos = m_user_effect_param.pos.XZ();
				break;
			}	
			case EEffectAnchor_SkillOwner:
			{
				shape.pos = caster->GetTransform()->GetPos().XZ();
			}
			break;
			case EEffectAnchor_Target:
			{
				std::shared_ptr<SceneUnit> target_su = this->GetEffectTarget();
				if (nullptr == target_su)
				{
					shape.pos = m_user_effect_param.pos.XZ();
				}
				else
				{
					shape.pos = target_su->GetTransform()->GetPos().XZ();
				}
			}
			break;
			default:
				break;
		}

		shape.dir = m_user_effect_param.dir;

		ESceneUnitFilterWayParams params;
		if (0 != filter_cfg->relations)
		{
			params.is_active[ESceneUnitFilterWay_Relation] = true;
			params.relations.caster = caster;
			params.relations.relations = filter_cfg->relations;
		}
		if (filter_cfg->limit_num > 0)
		{
			params.is_active[ESceneUnitFilterWay_LimitNum] = true;
			params.limit_num.num = filter_cfg->limit_num;
			params.limit_num.priority = filter_cfg->limit_num_priority;
		}
		if (0 != filter_cfg->unit_types)
		{
			params.is_active[ESceneUnitFilterWay_UnitType] = true;
			params.relations.caster = caster;
			params.relations.relations = filter_cfg->relations;
		}

		std::unordered_map<uint64_t, std::shared_ptr<SceneUnit>> ret = su_filter->FilterSceneUnit(shape, params);
		return ret;
	}
}
