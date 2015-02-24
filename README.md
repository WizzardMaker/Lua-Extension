# Lua-Extension

Functions:

lua_start(string filepath);
-Sets the path variable and initials the Lua libary

lua_stop();
-Resets the path variable

lua_add_var(string name, int/string var);
-Adds a varaible to the Lua interpreter

lua_execute_file();
-Executes the file with the in lua_start given path variable.