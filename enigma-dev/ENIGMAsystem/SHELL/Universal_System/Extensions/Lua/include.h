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
namespace enigma_user{
void lua_start(string filepath);
void lua_stop();
void lua_add_var(string name, int var);
void lua_add_var(string name, string var);
int lua_get_int(string name);
string lua_get_string(string name);
void lua_execute_file();
}