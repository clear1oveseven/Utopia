#include "SolLuaBindUtils.h"
#include <sol.hpp>	
#include "LogicModules/GameLogic/Scene/Effects/EffectBase.h"	
#include "ShareCode/Config/AutoCsvCode/effect/CsvEffectScriptConfig.h"	
#include "LogicModules/GameLogic/Scene/Effects/EffectScript/EffectScriptConfig.h"	
#include "LogicModules/GameLogic/Scene/SceneModule/SceneEffects/SceneEffects.h"	
#include "LogicModules/GameLogic/Scene/Effects/EffectConfigBase.h"

namespace SolLuaBind
{
	void LuaBind_GameLogic_EffectScriptConfig(lua_State *L)
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
                std::string name = "EffectScriptConfig";
				std::string name_space = "GameLogic";

				{
					sol::usertype<GameLogic::EffectScriptConfig> meta_table(
						"__StructName__", sol::property([]() {return "EffectScriptConfig"; })				
						,"CreateEffect", &GameLogic::EffectScriptConfig::CreateEffect				
						,"InitCfg", &GameLogic::EffectScriptConfig::InitCfg				
						,"GetClassName", &GameLogic::EffectScriptConfig::GetClassName				
						, sol::base_classes, sol::bases<
							GameLogic::EffectConfigBase 
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