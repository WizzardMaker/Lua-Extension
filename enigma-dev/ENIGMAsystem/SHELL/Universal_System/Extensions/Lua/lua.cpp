#include "include.h"
#include <string>
using std::string;
namespace enigma_user{
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
		const char *stringchar = String.c_str(); //Converts the std::string String into a const char
		
		lua_State *Lua = luaL_newstate();
		
		luaL_openlibs(Lua);
		luaL_dostring(Lua, stringchar);
		
		lua_getglobal(Lua, "returner"); //Puts the variable returner on the stack
		
		if(lua_isnumber(Lua,-1)){ //If returner is a number
			returner = (int)lua_tonumber(Lua, -1); //Gets the Variable returner from the stack
		}else if(lua_isstring(Lua, -1)){ //If returner is a string
			returner = (string)lua_tostring(Lua, -1); //Gets the Variable returner from the stack
		}else{
			returner = "ERROR! UNKNOW RETURNER TYPE OR ERROR IN THE SCRIPT!"; //If there is no variable called returner or there is an error in the script or returner is not a string/integer
		}
		
		lua_close(Lua);
		return returner;
	}
	variant lua_get_variable(string file, string variable){
		variant returner;
		const char *filechar = file.c_str(); //Converts the std::string file into a const char
		const char *variablechar = variable.c_str();
		
		lua_State *Lua = luaL_newstate();
		luaL_openlibs(Lua); //Open the libaries
		luaL_dofile(Lua, filechar); //Executes the Lua File
		
		lua_getglobal(Lua, variablechar); //Puts the variable returner on the stack
		
		if(lua_isnumber(Lua,-1)){ //If returner is a number
			returner = (int)lua_tonumber(Lua, -1); //Gets the Variable returner from the stack
		}else if(lua_isstring(Lua, -1)){ //If returner is a string
			returner = (string)lua_tostring(Lua, -1); //Gets the Variable returner from the stack
		}else{
			returner = "ERROR! UNKNOW VARIABLE TYPE OR ERROR IN SCRIPT: " + file + "!"; //If there is no variable called returner or there is an error in the script or returner is not a string/integer
		}
		
		lua_close(Lua);
		return returner; //Returns the variable	
	}
	variant luaF_execute_file_int1(string filepath,const std::function<int(int)> &f){
		lua::State state; //Creates a new Lua State
		state.set("cfunction", f);
		state.doFile(filepath); //Executes the Lua File
		return 1;
	}
	variant luaF_execute_file_int2(string filepath,const std::function<int(int, int)> &f){
		lua::State state; //Creates a new Lua State
		state.set("cfunction", f);
		state.doFile(filepath); //Executes the Lua File
		return 1;
	}
	variant luaF_execute_file_int3(string filepath,const std::function<int(int,int,int)> &f){
		lua::State state; //Creates a new Lua State
		state.set("cfunction", f);
		state.doFile(filepath); //Executes the Lua File
		return 1;
	}
	variant luaF_execute_file_str1(string filepath,const std::function<int(string)> &f){
		lua::State state; //Creates a new Lua State
		state.set("cfunction", f);
		state.doFile(filepath); //Executes the Lua File
		return 1;
	}
	variant luaF_execute_file_str2(string filepath,const std::function<int(string, string)> &f){
		lua::State state; //Creates a new Lua State
		state.set("cfunction", f);
		state.doFile(filepath); //Executes the Lua File
		return 1;
	}
}