
#include <sol.hpp>
#include <lua.h>
#include <iostream>
#include <assert.h>
#include "OwnType/TryOwnTypeSolDefine.h"
#include <stdio.h>
#include "UserType/TryUserType.h"
#include "UserType/TryUserTypeUtil.h"
#include <thread>

int LuaErrorFn(lua_State *L)
{
	return 0;
}

sol::protected_function_result LuaErrorProtectedFn(lua_State *L, sol::protected_function_result pfr)
{
	sol::error err = pfr;
	printf("LuaErrorProtectedFn %s\n", err.what());
	return pfr;
}

lua_State *main_lua = nullptr;
lua_State * MainLua()
{
	return main_lua;
}

int main(int argc, char **argv)
{
	sol::state lua;
	main_lua = lua.lua_state();
	lua.set_panic(LuaErrorFn);
	lua.open_libraries(sol::lib::base);

	lua.script("function f (a, b) print(a, b) return a, b end");
	sol::function f = lua["f"];
	TryOwnType::Head one_head;
	one_head.weight = 10.0f;
	one_head.param_int = 20;
	f(one_head);
	TryOwnType::Head another_head = f(one_head);
	printf("another_head { %f, %d } \n", another_head.weight, another_head.param_int);

	lua.script("function g (a, b, c) print(a, b) return a, b, c end");
	sol::function g = lua["g"];
	TryOwnType::Human one_human;
	one_human.name = "lxl";
	one_human.head = one_head;
	g(one_human);
	TryOwnType::Human anohter_human = g(one_human);
	printf("anohter_human {%s, %f, %d } \n", anohter_human.name.c_str(), anohter_human.head.weight, anohter_human.head.param_int);

	TryUserType::RegisterUserType();
	TryUserType::ExecuteLuaBindUserTypeFns(lua.lua_state());

	sol::protected_function_result fpr;
	{
		// load lua file
		fpr = lua.script_file("LuaCode/src_file_list.lua", LuaErrorProtectedFn);
		if (!fpr.valid())
			return -100;
		sol::table src_file_list = lua["src_file_list"];
		if (!src_file_list.valid())
			return -200;
		for (auto kv_pair : src_file_list)
		{
			sol::object ss = kv_pair.second;
			std::string str = ss.as<std::string>();
			fpr = lua.script_file("LuaCode/" + str, LuaErrorProtectedFn);
			if (!fpr.valid())
				return -300;
		}
	}

	{
		TryUserType::Scene scene;
		TryUserType::Sheep sheep("sheep", 10, 10, 10, 10, 10);
		TryUserType::Wolf wolf("wolf", 10, 10, 10, 10, 10, 10);
		TryUserType::Plant plant("plant", 10, 10, 10);
	}

	sol::protected_function lua_main_tick_fn = lua["MainTick"];
	bool game_exit = lua["game_exit"];
	while (!game_exit)
	{
		lua_main_tick_fn();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		game_exit = lua["game_exit"];
	}

	return 0;
}

