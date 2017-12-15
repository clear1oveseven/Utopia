#pragma once

#include <vector>
#include <unordered_map>
#include "Common/Geometry/Vector2.h"
#include "Common/Geometry/Vector3.h"

namespace GameLogic
{
	class Skill;
	class SceneUnit;

	struct UseSkillParam
	{
		void Reset()
		{
			target_suid = 0;				// ����Ŀ��
			target_su.reset();
			pos = Vector3::zero;			// ����Ŀ���
			dir = Vector2::zero;			// ���ܷ���
			face_dir = Vector2::zero;		//  ����ʹ�Ľ�ɫ�ĳ���
		}

		uint64_t target_suid = 0;
		std::weak_ptr<SceneUnit> target_su;
		Vector3 pos;
		Vector2 dir;
		Vector2 face_dir;
	};

	struct UseEffectParam
	{
		void Reset()
		{
			skill = nullptr;
			target_suid = 0;
			pos = Vector3::zero;
			dir = Vector2::zero;
		}

		std::shared_ptr<Skill> skill;
		uint64_t target_suid = 0;
		Vector3 pos;
		Vector2 dir;
	};

	enum EEffectEndCase
	{
		EEffectEndCase_Both = 0,
		EEffectEndCase_Done,
		EEffectEndCase_Break,
	};

	using EffectIdVec = std::vector<int>;

	struct EndEffectId
	{
		EEffectEndCase end_case = EEffectEndCase_Both;
		int id = 0;
	};
	using EndEffectIdVec = std::vector<EndEffectId>;

	struct TimeLineEffectId
	{
		int id = 0;
		int wait_ms = 0;
	};
	using TimeLineEffectIdVec = std::vector<TimeLineEffectId>;
	struct TimeLineEffectIdsConfig
	{
		TimeLineEffectIdVec effect_ids;
		int min_wait_ms = -1;
		int max_wait_ms = -1;
	};

	enum EEffectStage
	{
		EEffectStage_Wait = 0,
		EEffectStage_Begin,
		EEffectStage_Loop,
		EEffectStage_End,
	};

	enum EEffectType
	{
		EEffectType_Hurt,
		EEffectType_Heal,
		EEffectType_Attr,
		EEffectType_ForceMove,
	};

	enum EEffectFilterAnchor
	{
		EEffectAnchor_Pos,
		EEffectAnchor_SkillOwner,
		EEffectAnchor_Target,
	};

	enum EEffectFilterShape
	{
		EffectFilterShape_None = 0,
		EEffectFilterShape_Circle,
		EEffectFilterShape_Rect,
		EEffectFilterShape_Sector,
	};

	union EffectFilterShapeParam
	{
		 struct circle
		 {
			 float radius = 0;
			 int max_su_count = 0;
		 };

		 struct rect
		 {
			 float length = 0;
			 float width = 0;
			 int max_su_count = 0;
		 };

		 struct sector
		 {
			 float angles = 0;
			 int max_su_count = 0;
		 };
	};

	enum EEffectFilterRelation
	{
		EEffectFilterRelation_Self = 0,
		EEffectFilterRelation_Friend,
		EEffectFilterRelation_Enemy,
	};

	struct EffectFilterOption
	{
		EEffectFilterAnchor anchor = EEffectAnchor_Pos;
		EEffectFilterShape shape = EffectFilterShape_None;
		EffectFilterShapeParam shape_param;
		int filter_relation;
	};
}
