#include "EffectScript.h"
#include "GameLogic/Scene/NewScene.h"
#include "GameLogic/Scene/SceneUnit/SceneUnit.h"
#include "GameLogic/Scene/SceneUnitModules/SceneUnitFightParam.h"
#include "EffectScriptConfig.h"
#include "GameLogic/Scene/Defines/EffectUtils.h"
#include "Utils/LuaUtils.h"
#include "SolLuaBindUtils.h"

namespace GameLogic
{
	EffectScript::EffectScript(const EffectConfigBase * cfg, SceneEffects * scene_effects, uint64_t effect_key) 
		: EffectBase(cfg, scene_effects, effect_key)
	{
		m_cfg = dynamic_cast<const EffectScriptConfig *>(cfg);
		assert(m_cfg);

		sol::state_view lsv(LuaUtils::luaState);
		sol::table typeDefine = SolLuaBindUtils::GetLuaNameSpaceTable(lsv, m_cfg->GetClassName());
		assert(typeDefine.valid());
		sol::protected_function newFn = typeDefine["new"];
		newFn.error_handler = LuaUtils::ProtectFnErrorHandler();
		m_lua_effect_script = newFn(typeDefine, this, nullptr);
		assert(m_lua_effect_script.valid());
	}

	EffectScript::~EffectScript()
	{
	}

	void EffectScript::OnLateBegin()
	{
		sol::protected_function luaFn = m_lua_effect_script["on_late_begin"];
		luaFn.error_handler = LuaUtils::ProtectFnErrorHandler();
		luaFn(m_lua_effect_script);
	}

	bool EffectScript::IsDone()
	{
		bool is_done = m_lua_effect_script.get_or("is_done", true);
		return is_done;
	}

	void EffectScript::OnLateLoop(int64_t now_ms, int64_t delta_ms)
	{
		sol::protected_function luaFn = m_lua_effect_script["on_late_loop"];
		luaFn.error_handler = LuaUtils::ProtectFnErrorHandler();
		luaFn(m_lua_effect_script, now_ms, delta_ms);
	}

	void EffectScript::OnLateEnd(EEffectEndCase end_case)
	{
		sol::protected_function luaFn = m_lua_effect_script["on_late_end"];
		luaFn.error_handler = LuaUtils::ProtectFnErrorHandler();
		luaFn(m_lua_effect_script);
	}
}