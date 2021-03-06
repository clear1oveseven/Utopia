#include "SolLuaBindUtils.h"
#include <sol.hpp>	
#include "ShareCode/Common/Utils/Ticker.h"	
#include "LogicModules/GameLogic/Scene/TestScene.h"	
#include "LogicModules/GameLogic/Scene/NewScene.h"	
#include "LogicModules/GameLogic/GameLogicModule.h"

namespace SolLuaBind
{
	void LuaBind_GameLogic_TestScene(lua_State *L)
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
                std::string name = "TestScene";
				std::string name_space = "GameLogic";

				{
					sol::usertype<GameLogic::TestScene> meta_table(
						sol::constructors<				
						GameLogic::TestScene(GameLogicModule *)
						>(),
						"__StructName__", sol::property([]() {return "TestScene"; })				
						, sol::base_classes, sol::bases<
							GameLogic::NewScene 
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