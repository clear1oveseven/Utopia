#include "SolLuaBindUtils.h"
#include <sol.hpp>	
#include "Libs/3rdpartLibs/recastnavigation/RecastDemo/Include/InputGeom.h"	
#include "Libs/3rdpartLibs/recastnavigation/Detour/Include/DetourNavMeshQuery.h"	
#include "Recast.h"	
#include "DetourCrowd.h"	
#include "LogicModules/GameLogic/Scene/Navigation/NavMesh.h"	
#include "LogicModules/GameLogic/Scene/Navigation/NavMeshUtil.h"	
#include "ShareCode/Common/Geometry/Vector3.h"	
#include "DetourTileCache.h"	
#include "ShareCode/Common/Geometry/GeometryDefine.h"	
#include "Libs/3rdpartLibs/recastnavigation/Detour/Include/DetourNavMesh.h"

namespace SolLuaBind
{
	void LuaBind_GameLogic_NavMesh(lua_State *L)
	{
		struct LuaBindImpl
		{
			struct ForOverloadFns
			{
				using TypeAlias_1 = const Vector3 &;
				using TypeAlias_2 = unsigned int *;
				using TypeAlias_3 = Vector3 &;
				using TypeAlias_4 = bool;
				static TypeAlias_4 FindNearestPoint1(GameLogic::NavMesh &cls, TypeAlias_1 p1, TypeAlias_2 p2, TypeAlias_3 p3)
				{
					return cls.FindNearestPoint(p1, p2, p3);
				}
				using TypeAlias_5 = const Vector3 &;
				using TypeAlias_6 = const Vector3;
				using TypeAlias_7 = unsigned int *;
				using TypeAlias_8 = Vector3 &;
				using TypeAlias_9 = bool;
				static TypeAlias_9 FindNearestPoint2(GameLogic::NavMesh &cls, TypeAlias_5 p1, TypeAlias_6 p2, TypeAlias_7 p3, TypeAlias_8 p4)
				{
					return cls.FindNearestPoint(p1, p2, p3, p4);
				}
			};
			
			struct ForPropertyField
			{
			};			
			

			static void DoLuaBind(lua_State *L)
			{
                std::string name = "NavMesh";
				std::string name_space = "GameLogic";

				{
					sol::usertype<GameLogic::NavMesh> meta_table(
						sol::constructors<				
						GameLogic::NavMesh()
						>(),
						"__StructName__", sol::property([]() {return "NavMesh"; })				
						,"UpdateTerrian", &GameLogic::NavMesh::UpdateTerrian				
						,"LoadTerrain", &GameLogic::NavMesh::LoadTerrain				
						,"GetCrowd", &GameLogic::NavMesh::GetCrowd				
						,"GetNavMeshQuery", &GameLogic::NavMesh::GetNavMeshQuery				
						,"Raycast", &GameLogic::NavMesh::Raycast				
						,"GetPolyRef", &GameLogic::NavMesh::GetPolyRef				
						,"GetArea", &GameLogic::NavMesh::GetArea				
						,"FindNearestPoint", sol::overload(ForOverloadFns::FindNearestPoint1, ForOverloadFns::FindNearestPoint2)
					);
					SolLuaBindUtils::BindLuaUserType(sol::state_view(L), meta_table, name, name_space);
				}
            
				{
					sol::table ns_table = SolLuaBindUtils::GetOrNewLuaNameSpaceTable(sol::state_view(L), name_space)[name];
				}
			}
		};

		LuaBindImpl::DoLuaBind(L);
	}
}