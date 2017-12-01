#include "SceneUnitFightParam.h"
#include "Common/Utils/TupleUtil.h"
#include "GameLogic/Scene/Defines/SceneEventID.h"
#include "GameLogic/Scene/SceneUnit/SceneUnitEventProxy.h"

namespace GameLogic
{
	SceneUnitFightParam::SceneUnitFightParam() : SceneUnitModule(MODULE_TYPE)
	{
		memset(m_params, 0, sizeof(m_params));
		memset(m_fix_params, 0, sizeof(m_fix_params));
	}

	SceneUnitFightParam::~SceneUnitFightParam()
	{

	}

	FightParam * SceneUnitFightParam::GetParam(NetProto::EFightParam efp)
	{
		if (efp < 0 || efp >= NetProto::EFP_COUNT)
			return nullptr;
		return m_params[efp];
	}
	FightParam * SceneUnitFightParam::GetParamFix(NetProto::EFightParam efp)
	{
		if (efp < 0 || efp >= NetProto::EFP_COUNT)
			return nullptr;
		return m_fix_params[efp];
	}
	void SceneUnitFightParam::AddBaseValue(NetProto::EFightParam efp, int val, bool recal, int unique_id)
	{
		if (efp < 0 || efp >= NetProto::EFP_COUNT || nullptr == m_params[efp])
			return;
		m_params[efp]->AddBaseValue(val, recal, unique_id);

	}
	void SceneUnitFightParam::RemoveBaseValue(NetProto::EFightParam efp, int val, bool recal, int unique_id)
	{
		if (efp < 0 || efp >= NetProto::EFP_COUNT || nullptr == m_params[efp])
			return;
		m_params[efp]->RemoveBaseValue(val, recal, unique_id);
	}
	void SceneUnitFightParam::AddBaseValueFix(NetProto::EFightParam efp, int val, bool recal, int unique_id)
	{
		if (efp < 0 || efp >= NetProto::EFP_COUNT || nullptr == m_fix_params[efp])
			return;
		m_fix_params[efp]->AddBaseValue(val, recal, unique_id);
	}
	void SceneUnitFightParam::RemoveBaseValueFix(NetProto::EFightParam efp, int val, bool recal, int unique_id)
	{
		if (efp < 0 || efp >= NetProto::EFP_COUNT || nullptr == m_fix_params[efp])
			return;
		m_fix_params[efp]->RemoveBaseValue(val, recal, unique_id);
	}
	void SceneUnitFightParam::AddExtraPercent(NetProto::EFightParam efp, int val, bool recal, int unique_id)
	{
		if (efp < 0 || efp >= NetProto::EFP_COUNT || nullptr == m_params[efp])
			return;
		m_params[efp]->AddExtraPercent(val, recal, unique_id);
	}
	void SceneUnitFightParam::RemoveExtraPercent(NetProto::EFightParam efp, int val, bool recal, int unique_id)
	{
		if (efp < 0 || efp >= NetProto::EFP_COUNT || nullptr == m_params[efp])
			return;
		m_params[efp]->RemoveExtraPercent(val, recal, unique_id);
	}
	void SceneUnitFightParam::AddExtraPercentFix(NetProto::EFightParam efp, int val, bool recal, int unique_id)
	{
		if (efp < 0 || efp >= NetProto::EFP_COUNT || nullptr == m_fix_params[efp])
			return;
		m_fix_params[efp]->AddExtraPercent(val, recal, unique_id);
	}
	void SceneUnitFightParam::RemoveExtraPercentFix(NetProto::EFightParam efp, int val, bool recal, int unique_id)
	{
		if (efp < 0 || efp >= NetProto::EFP_COUNT || nullptr == m_fix_params[efp])
			return;
		m_fix_params[efp]->RemoveExtraPercent(val, recal, unique_id);
	}
	void SceneUnitFightParam::AddExtraValue(NetProto::EFightParam efp, int val, bool recal, int unique_id)
	{
		if (efp < 0 || efp >= NetProto::EFP_COUNT || nullptr == m_params[efp])
			return;
		m_params[efp]->AddExtraValue(val, recal, unique_id);
	}
	void SceneUnitFightParam::RemoveExtraValue(NetProto::EFightParam efp, int val, bool recal, int unique_id)
	{
		if (efp < 0 || efp >= NetProto::EFP_COUNT || nullptr == m_params[efp])
			return;
		m_params[efp]->RemoveExtraValue(val, recal, unique_id);
	}
	void SceneUnitFightParam::AddExtraValueFix(NetProto::EFightParam efp, int val, bool recal, int unique_id)
	{
		if (efp < 0 || efp >= NetProto::EFP_COUNT || nullptr == m_fix_params[efp])
			return;
		m_fix_params[efp]->AddExtraValue(val, recal, unique_id);
	}
	void SceneUnitFightParam::RemoveExtraValueFix(NetProto::EFightParam efp, int val, bool recal, int unique_id)
	{
		if (efp < 0 || efp >= NetProto::EFP_COUNT || nullptr == m_fix_params[efp])
			return;
		m_fix_params[efp]->RemoveExtraValue(val, recal, unique_id);
	}
	void SceneUnitFightParam::Recal(NetProto::EFightParam efp, bool include_fix)
	{
		if (efp < 0 || efp >= NetProto::EFP_COUNT)
			return;
		if (nullptr != m_params[efp])
			m_params[efp]->Recal();
		if (include_fix && NULL != m_fix_params[efp])
			m_fix_params[efp]->Recal();

	}
	int SceneUnitFightParam::GetValue(NetProto::EFightParam efp, bool include_fix)
	{
		int value = 0;
		if (efp < 0 || efp >= NetProto::EFP_COUNT)
			return 0;
		if (nullptr != m_params[efp])
			value += m_params[efp]->GetValue(true);
		if (include_fix && NULL != m_fix_params[efp])
			value += m_fix_params[efp]->GetValue(true);
		return value;
	}
	void SceneUnitFightParam::RecalFix(NetProto::EFightParam efp)
	{
		if (efp < 0 || efp >= NetProto::EFP_COUNT)
			return;
		if (nullptr != m_fix_params[efp])
			m_fix_params[efp]->Recal();
	}
	int SceneUnitFightParam::GetValueFix(NetProto::EFightParam efp, bool recal)
	{
		if (efp < 0 || efp >= NetProto::EFP_COUNT || nullptr == m_fix_params[efp])
			return 0;
		return m_fix_params[efp]->GetValue(true);
	}

	void SceneUnitFightParam::OnValueChange(bool is_fix, NetProto::EFightParam efp, int new_value, int old_value)
	{
		m_ev_queue.push(std::make_tuple(is_fix, efp, old_value, new_value));
		while (!m_ev_queue.empty() && !m_ev_firing)
		{
			auto t = m_ev_queue.front();
			m_ev_queue.pop();
			Tuple::Apply(std::bind(&SceneUnitFightParam::FireEventHelp, this, 
				std::placeholders::_1, std::placeholders::_2, 
				std::placeholders::_3, std::placeholders::_4), t);
		}
	}

	void SceneUnitFightParam::FireEventHelp(bool is_fix, NetProto::EFightParam efp, int new_value, int old_value)
	{
		m_ev_firing = true;
		this->GetEvProxy()->Fire(ESU_FightParamChange, is_fix, efp, new_value, old_value);
		m_ev_firing = false;
	}

	void SceneUnitFightParam::OnInit()
	{
		this->ForTestInitParam();
		this->ForTestInitFixParam();
	}

	void SceneUnitFightParam::OnDestroy()
	{
		for (int i = 0; i < NetProto::EFP_COUNT; ++i)
		{
			delete m_params[i]; m_params[i] = nullptr;
			delete m_fix_params[i]; m_fix_params[i] = nullptr;
		}
	}

	FightParam * DefaultFightParameter(NetProto::EFightParam efp, int min_value, int min_base_value, int min_extra_value, int min_add_percent, int max_add_percent)
	{
		FightParam *fp = new FightParam();
		fp->SetFightParam(efp);
		fp->SetMinValue(min_value);
		fp->SetMaxValue(INT32_MAX);

		fp->SetBaseValueCalStrategy(NumUtil::ECS_Overlay);
		fp->SetBaseValueMin(min_base_value, false);
		fp->SetBaseValueMax(INT32_MAX, false);

		fp->SetExtraPercentCalStrategy(NumUtil::ECS_Overlay, false);
		fp->SetExtraPercentMin(min_add_percent, false);
		fp->SetExtraPercentMax(max_add_percent, false);

		fp->SetExtraValueCalStrategy(NumUtil::ECS_Overlay, false);
		fp->SetExtraValueMin(min_extra_value, false);
		fp->SetExtraValueMax(INT32_MAX, false);

		fp->Recal();
		return fp;
	}

	void SceneUnitFightParam::ForTestInitParam()
	{
		memset(m_params, 0, sizeof(m_params));
		// ����������ֵ��һ������base_value>=0 value >= 0�������Ĳ�������
		{
			FightParam *fp = DefaultFightParameter(NetProto::EFP_MaxHP, 1, 1, 0, 0, INT_MAX);
			assert(nullptr == m_params[fp->GetFightParam()]);
			m_params[fp->GetFightParam()] = fp;
		}
		{
			FightParam *fp = DefaultFightParameter(NetProto::EFP_MaxMP, 1, 1, 0, 0, INT_MAX);
			assert(nullptr == m_params[fp->GetFightParam()]);
			m_params[fp->GetFightParam()] = fp;
		}
		{
			FightParam *fp = DefaultFightParameter(NetProto::EFP_MoveSpeed, 0, 0, INT_MIN, INT_MIN, INT_MAX);
			assert(nullptr == m_params[fp->GetFightParam()]);
			m_params[fp->GetFightParam()] = fp;
		}
		{
			// ����룬��С�������250���룬�ٷֱ�������
			FightParam *fp = DefaultFightParameter(NetProto::EFP_AttackSpeed, 250, 0, INT_MIN, INT_MIN, INT_MAX);
			assert(nullptr == m_params[fp->GetFightParam()]);
			m_params[fp->GetFightParam()] = fp;
			fp->SetPercentAsDenominator(true);
		}
		{
			FightParam *fp = DefaultFightParameter(NetProto::EFP_AttackDist, 0, 0, INT_MIN, INT_MIN, INT_MAX);
			assert(nullptr == m_params[fp->GetFightParam()]);
			m_params[fp->GetFightParam()] = fp;
		}
		{
			FightParam *fp = DefaultFightParameter(NetProto::EFP_PhyAttack, 0, 0, INT_MIN, INT_MIN, INT_MAX);
			assert(nullptr == m_params[fp->GetFightParam()]);
			m_params[fp->GetFightParam()] = fp;
		}
		{
			FightParam *fp = DefaultFightParameter(NetProto::EFP_MagicAttack, 0, 0, INT_MIN, INT_MIN, INT_MAX);
			assert(nullptr == m_params[fp->GetFightParam()]);
			m_params[fp->GetFightParam()] = fp;
		}
		{
			FightParam *fp = DefaultFightParameter(NetProto::EFP_PhyHurt, 0, 0, INT_MIN, INT_MIN, INT_MAX);
			assert(nullptr == m_params[fp->GetFightParam()]);
			m_params[fp->GetFightParam()] = fp;
		}
		{
			FightParam *fp = DefaultFightParameter(NetProto::EFP_MagicHurt, 0, 0, INT_MIN, INT_MIN, INT_MAX);
			assert(nullptr == m_params[fp->GetFightParam()]);
			m_params[fp->GetFightParam()] = fp;
		}
		{
			FightParam *fp = DefaultFightParameter(NetProto::EFP_PhyDefense, 0, 0, INT_MIN, INT_MIN, INT_MAX);
			assert(nullptr == m_params[fp->GetFightParam()]);
			m_params[fp->GetFightParam()] = fp;
		}
		{
			FightParam *fp = DefaultFightParameter(NetProto::EFP_MagicDefense, 0, 0, INT_MIN, INT_MIN, INT_MAX);
			assert(nullptr == m_params[fp->GetFightParam()]);
			m_params[fp->GetFightParam()] = fp;
		}

		// �������״̬ ����base_valueΪ0�� ��extra_value������״̬��Ч
		{
			FightParam *fp = DefaultFightParameter(NetProto::EFP_Dizziness, 0, 0, 0, 0, 0);
			assert(nullptr == m_params[fp->GetFightParam()]);
			m_params[fp->GetFightParam()] = fp;
			fp->SetBaseValueMax(0);
			fp->SetBaseValueMin(0);
		}
		{
			FightParam *fp = DefaultFightParameter(NetProto::EFP_Silence, 0, 0, 0, 0, 0);
			assert(nullptr == m_params[fp->GetFightParam()]);
			m_params[fp->GetFightParam()] = fp;
			fp->SetBaseValueMax(0);
			fp->SetBaseValueMin(0);
		}
		{
			FightParam *fp = DefaultFightParameter(NetProto::EFP_Blind, 0, 0, 0, 0, 0);
			assert(nullptr == m_params[fp->GetFightParam()]);
			m_params[fp->GetFightParam()] = fp;
			fp->SetBaseValueMax(0);
			fp->SetBaseValueMin(0);
		}
		{
			FightParam *fp = DefaultFightParameter(NetProto::EFP_Immobilized, 0, 0, 0, 0, 0);
			assert(nullptr == m_params[fp->GetFightParam()]);
			m_params[fp->GetFightParam()] = fp;
			fp->SetBaseValueMax(0);
			fp->SetBaseValueMin(0);
		}

		// ���ó�ʼֵ
		{
			m_params[NetProto::EFP_MaxHP]->AddBaseValue(1000);
			m_params[NetProto::EFP_MaxMP]->AddBaseValue(1000);
			m_params[NetProto::EFP_MoveSpeed]->AddBaseValue(12);
			m_params[NetProto::EFP_AttackDist]->AddBaseValue(2000); // ���������ʼΪ2��ÿ��
			m_params[NetProto::EFP_AttackDist]->AddBaseValue(6);
			m_params[NetProto::EFP_PhyAttack]->AddBaseValue(10);
			m_params[NetProto::EFP_MagicAttack]->AddBaseValue(10);
			m_params[NetProto::EFP_PhyDefense]->AddBaseValue(10);
			m_params[NetProto::EFP_MagicDefense]->AddBaseValue(10);
		}

		auto value_change_cb = std::bind(&SceneUnitFightParam::OnValueChange, this, false,
			std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
		for (int i = 0; i < NetProto::EFP_COUNT; ++i)
		{
			if (nullptr != m_params[i])
			{
				m_params[i]->SetValueChangeCallback(value_change_cb);
			}
		}
	}
	void SceneUnitFightParam::ForTestInitFixParam()
	{
		auto value_change_cb = std::bind(&SceneUnitFightParam::OnValueChange, this, true,
			std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
		for (int i = 0; i < NetProto::EFP_COUNT; ++i)
		{
			if (nullptr != m_params[i])
			{
				m_fix_params[i] = DefaultFightParameter((NetProto::EFightParam)i, 0, 0, INT_MIN, INT_MIN, INT_MAX);
				m_fix_params[i]->SetValueChangeCallback(value_change_cb);
			}
		}
	}
}