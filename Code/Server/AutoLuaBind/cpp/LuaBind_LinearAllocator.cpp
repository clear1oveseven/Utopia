#include "SolLuaBindUtils.h"
#include <sol.hpp>	
#include "Libs/3rdpartLibs/recastnavigation/RecastDemo/Include/InputGeom.h"	
#include "DetourTileCacheBuilder.h"	
#include "LogicModules/GameLogic/Scene/Navigation/NavMeshUtil.h"	
#include "Libs/3rdpartLibs/recastnavigation/Detour/Include/DetourNavMeshBuilder.h"	
#include "DetourTileCache.h"

namespace SolLuaBind
{
	void LuaBind_LinearAllocator(lua_State *L)
	{
		struct LuaBindImpl
		{
			struct ForOverloadFns
			{
			};
			
			struct ForPropertyField
			{
			};			
			

			static void DoLuaBind(lua_State *L)
			{
                std::string name = "LinearAllocator";
				std::string name_space = "";

				{
					sol::usertype<LinearAllocator> meta_table(
						sol::constructors<				
						LinearAllocator(const unsigned int)
						>(),
						"__StructName__", sol::property([]() {return "LinearAllocator"; })				
						,"buffer", &LinearAllocator::buffer				
						,"capacity", &LinearAllocator::capacity				
						,"top", &LinearAllocator::top				
						,"high", &LinearAllocator::high				
						,"resize", &LinearAllocator::resize				
						,"reset", &LinearAllocator::reset				
						,"alloc", &LinearAllocator::alloc				
						,"free", &LinearAllocator::free				
						, sol::base_classes, sol::bases<
							dtTileCacheAlloc 
						>()
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