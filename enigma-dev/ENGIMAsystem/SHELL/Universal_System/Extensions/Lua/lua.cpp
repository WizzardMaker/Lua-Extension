#include "include.h"
#include <string>
using std::string;
namespace enigma_user{
	/* These seem to dont work...
	lua_State lua_start(void){ //ENIGMA cant read the function if the return is a lua_State...
		lua_State *Lua = luaL_newstate();
		luaL_openlibs(Lua);
		return Lua;
	}
	lua_State lua_stop(lua_State *Lua){ //This cant work if we dont have a lua_State variable from the function above
		lua_close(Lua);
		return;
	}
	*/
	variant lua_execute_file(string file){
		variant returner; //I have to use a variant to let it get any type
		const char *filechar = file.c_str(); //Converts the std::string file into a const char
		
		lua_State *Lua = luaL_newstate(); //Creates a new Lua State
		
		luaL_openlibs(Lua); //Open the libaries
		luaL_dofile(Lua, filechar); //Executes the Lua File
		
		lua_getglobal(Lua, "returner"); //Puts the variable returner on the stack
		
		if(lua_isnumber(Lua,-1)){ //If returner is a number
			returner = (int)lua_tonumber(Lua, -1); //Gets the Variable returner from the stack
		}else if(lua_isstring(Lua, -1)){ //If returner is a string
			returner = (string)lua_tostring(Lua, -1); //Gets the Variable returner from the stack
		}else{
			returner = "ERROR! UNKNOW RETURNER TYPE OR ERROR IN SCRIPT: " + file + "!"; //If there is no variable called returner or there is an error in the script or returner is not a string/integer
		}
		
		lua_close(Lua); //Closes Lua
		return returner; //Returns the variable
	}
	variant lua_execute_string(string String){
		variant returner;
		const char* *stringchar = String.c_str(); //Converts the std::string String into a const char
		
		lua_State *Lua = luaL_newstate();
		
		luaL_openlibs(Lua);
		luaL_dostring(Lua, String);
		
		lua_getglobal(Lua, "returner"); //Puts the variable returner on the stack
		
		if(lua_isnumber(Lua,-1)){ //If returner is a number
			returner = (int)lua_tonumber(Lua, -1); //Gets the Variable returner from the stack
		}else if(lua_isstring(Lua, -1)){ //If returner is a string
			returner = (string)lua_tostring(Lua, -1); //Gets the Variable returner from the stack
		}else{
			returner = "ERROR! UNKNOW RETURNER TYPE OR ERROR IN SCRIPT: " + file + "!"; //If there is no variable called returner or there is an error in the script or returner is not a string/integer
		}
		
		lua_close(Lua);
		return returner;
	}
}