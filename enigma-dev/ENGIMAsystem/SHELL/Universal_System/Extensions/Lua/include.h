#include "../../var4.h"
#include "../../dynamic_args.h"
#include <stdarg.h>
#include <array>
#include <functional>
#include <luastate.h>

namespace enigma_user{
variant lua_execute_file(string file);
variant lua_execute_string(string String);
variant lua_get_variable(string file, string variable);
variant luaF_execute_file_int1(string filepath,const std::function<int(int)> &f);
variant luaF_execute_file_int2(string filepath,const std::function<int(int, int)> &f,int arguments);
variant luaF_execute_file_int3(string filepath,const std::function<int(int, int, int)> &f,int arguments);
variant luaF_execute_file_str1(string filepath,const std::function<int(string)> &f,int arguments);
variant luaF_execute_file_str2(string filepath,const std::function<int(string, string)> &f,int arguments);
}