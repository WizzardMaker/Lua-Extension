# Lua-Extension
This is a extension for ENIGMA
# Tutorial
Install:
Extension just copy the folder "enigma-dev" from the repository to your ENIGMA installation and start ENGIMA, for everybody who gets Syntax errors just check if you have enabled the function in the Game Settings under ENIGMA / Extensions

Code:
You start lua with the command:

lua_start(string path) - path = the path to your *.lua file


You can execute the file with:

lua_execute_file()


You can add Variables to the Lua Stack with:

lua_add_variable(string name, int variable)

lua_add_variable(string name, string variable)


And get Variables with:

lua_get_int(string name) - for Int type Variables (Those with no floating point)

lua_get_string(string name) - for String type Variables


And stop Lua with the command:

lua_stop() - This is not necessary as lua_start(...) is just to set the path but I think it looks nice

lua_start() and lua_stop will be changed in the future!
