#include "UserType/TryUserTypeUtil.h"
#include <sol.hpp>
#include "try.pb.h"

namespace TryUserType
{
    void LuaBindPB_NetProto_TryMsg_TryNestEnum(lua_State *L)
	{
		struct PBMsg 
		{
			static void DoLuaBind(lua_State *L, const std::string &name_space, const std::string &name)
			{
				assert(!name.empty());
				sol::state_view lua(L);
				sol::table ns_table = GetOrNewLuaNameSpaceTable(lua, name_space);
				{
					sol::optional<sol::object> opt_object = ns_table[name];
					assert(!opt_object);
				}
				ns_table.new_enum(name,
					"a", NetProto::TryMsg_TryNestEnum::TryMsg_TryNestEnum_a,
					"b", NetProto::TryMsg_TryNestEnum::TryMsg_TryNestEnum_b
				);
			}
		};
		
		PBMsg::DoLuaBind(L, "NetProto.TryMsg", "TryNestEnum"); 
	}
}
 	