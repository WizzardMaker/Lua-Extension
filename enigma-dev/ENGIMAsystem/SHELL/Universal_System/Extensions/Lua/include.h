#include "../../var4.h"
extern "C"{
#include <lauxlib.h>
#include <lualib.h>
#include <lua.h>
}

namespace enigma_user{
//lua_State lua_start(void);
//lua_State lua_stop(lua_State *Lua);
variant lua_execute_file(const char* file);
void lua_execute_string(const char* String);
//variant lua_call_function(lua_State *Lua,string file, string function, int results,variant argument0 , ...);
}