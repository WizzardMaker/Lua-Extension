#include "../../var4.h"
#include "../../dynamic_args.h"
#include "../../object.h"
#include "../../instance_iterator.h"
#include "../../scalar.h"
#include "Widget_Systems/widgets_mandatory.h"
#include <stdarg.h>
#include <array>
#include <functional>
#include <LuaState.h>
/*extern "C"{
#include <lauxlib.h>
#include <lualib.h>
#include <lua.h>
}*/
namespace enigma_user{
void lua_start(string filepath);
void lua_stop();
void lua_add_var(string name, int var);
void lua_add_var(string name, string var);
//variant lua_get_variable(string file, string variable);
//variant lua_execute_file(string file);
//variant lua_execute_string(string String);
//variant luaF_execute_file(string filepath, const std::function<int(int)> &f,int arguments);
//variant lua_call_function(lua_State *Lua,string file, string function, int results,);
//variant luaF_execute_file(string filepath,Funct f);
void luaI_execute_file();
/*variant luaF_execute_file(string filepath,const std::function<int(int)> &f);
variant luaF_execute_file(string filepath,const std::function<int(int, int)> &f,int arguments);
variant luaF_execute_file(string filepath,const std::function<int(int, int, int)> &f,int arguments);
variant luaF_execute_file(string filepath,const std::function<int(string)> &f,int arguments);
variant luaF_execute_file(string filepath,const std::function<int(string, string)> &f,int arguments);
*/
}
//const std::function<variant(variant, variant)> &f