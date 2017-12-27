#pragma once

#include "GameLogic/Scene/SceneModule/SceneModule.h"
#include "GameLogic/Scene/Defines/EffectDefine.h"
#include "Common/Geometry/GeometryDefine.h"
#include "SceneUnitQTree.h"
#include <vector>

namespace GameLogic
{
	enum ESceneUnitFilterWay
	{
		ESceneUnitFilterWay_ExculdeSuids,
		ESceneUnitFilterWay_UnitType,
		ESceneUnitFilterWay_Relation,
		ESceneUnitFilterWay_ShapeCircle,
		ESceneUnitFilterWay_ShapeObb2,
		ESceneUnitFilterWay_ShapeSector,
		ESceneUnitFilterWay_LimitNum,
		ESceneUnitFilterWay_Count,
	};

	struct ESceneUnitFilterWayParams
	{
		ESceneUnitFilterWayParams()
		{
			memset(is_active, 0, sizeof(is_active));
		}

		bool is_active[ESceneUnitFilterWay_Count];

		struct
		{
			std::unordered_set<uint64_t> excludeSuids;
		} exclude_suids;

		struct
		{
			std::shared_ptr<SceneUnit> caster;
			int relation;
		} relation;

		struct
		{
			OBB2 oob2;
		} shape_obb2;

		struct
		{
			Circle circle;
		} shape_circle;
		
		struct
		{
			Sector sector;
		} shape_sector;

		struct
		{
			int num;
		} limit_num;

		struct  
		{
			int allow_types;
		} unit_type;
	};

	class SceneUnitFilter : public SceneModule
	{
	public:
		static const ESceneModule MODULE_TYPE = ESceneModule_UnitFilter;
	public:
		SceneUnitFilter();
		virtual ~SceneUnitFilter() override;

	public:
		std::unordered_map<uint64_t, std::shared_ptr<SceneUnit>> FilterSceneUnit(EffectFilterShape shape);
		std::unordered_map<uint64_t, std::shared_ptr<SceneUnit>> FilterSceneUnit(EffectFilterShape shape, ESceneUnitFilterWayParams &params);
		std::unordered_map<uint64_t, std::shared_ptr<SceneUnit>> FilterSceneUnit(EffectFilterShape shape, std::shared_ptr<SceneUnit> caster, int relation);

	protected:
		using FilterWay = void(const ESceneUnitFilterWayParams &param, std::unordered_map<uint64_t, std::shared_ptr<SceneUnit>> &units);
		FilterWay *m_filter_way[ESceneUnitFilterWay_Count];
		void ExtraFilterProcess(const ESceneUnitFilterWayParams &params, std::unordered_map<uint64_t, std::shared_ptr<SceneUnit>> &units);

		static void FilterUnitType(const ESceneUnitFilterWayParams &param, std::unordered_map<uint64_t, std::shared_ptr<SceneUnit>> &units);
		static void FilterExcludeSuids(const ESceneUnitFilterWayParams &param, std::unordered_map<uint64_t, std::shared_ptr<SceneUnit>> &units);
		static void FilterRelation(const ESceneUnitFilterWayParams &param, std::unordered_map<uint64_t, std::shared_ptr<SceneUnit>> &units);
		static void FilterShapeObb2(const ESceneUnitFilterWayParams &param, std::unordered_map<uint64_t, std::shared_ptr<SceneUnit>> &units);
		static void FilterShapeCircle(const ESceneUnitFilterWayParams &param, std::unordered_map<uint64_t, std::shared_ptr<SceneUnit>> &units);
		static void FilterShapeSector(const ESceneUnitFilterWayParams &param, std::unordered_map<uint64_t, std::shared_ptr<SceneUnit>> &units);
		static void FilterLimitNum(const ESceneUnitFilterWayParams &param, std::unordered_map<uint64_t, std::shared_ptr<SceneUnit>> &units);

	protected:
		std::unordered_map<uint64_t, std::shared_ptr<SceneUnit>> FindUnits(AABB2 rect);
		std::unordered_map<uint64_t, std::shared_ptr<SceneUnit>> FindUnits(OBB2 obb);
		std::unordered_map<uint64_t, std::shared_ptr<SceneUnit>> FindUnits(Circle circle);
		std::unordered_map<uint64_t, std::shared_ptr<SceneUnit>> FindUnits(Sector sector);
		void FindUnits(AABB2 rect, std::unordered_map<uint64_t, std::shared_ptr<SceneUnit>> &out_ret);

	protected:
		virtual bool OnAwake() override;
		virtual void OnUpdate() override;

		SceneUnitQTree m_qtree;
		std::unordered_map<uint64_t, SceneUnitQTreeNodeUnit *> m_id_unit_map;
		void OnSceneUnitEnterScene(std::shared_ptr<SceneUnit> su);
		void OnSceneUnitLeaveScene(std::shared_ptr<SceneUnit> su);
		void OnSceneUnitPosChange(std::shared_ptr<SceneUnit> su, Vector3 old_pos, Vector3 new_pos);
	};
}
