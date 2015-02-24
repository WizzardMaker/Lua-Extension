#include "include.h"
#include <string>
using std::string;
lua::State state;
string path;
namespace enigma_user{
	void draw_string(gs_scalar x, gs_scalar y, string str){
		extern void draw_text(gs_scalar x, gs_scalar y, variant str);
		draw_text(x, y, str);
	}
	
	void lua_start(string filepath){
		state.initialize(true);
		extern enigma::instance_t instance_create(int x,int y,int object);
		state.set( "instance_create" , 	 &instance_create);
		extern	bool object_exists(int objid);
		state.set( "object_exists" , & object_exists );
		extern	void object_set_depth(int objid, int val);
		state.set( "object_set_depth" , & object_set_depth );
		extern	void object_set_mask(int objid, int val);
		state.set( "object_set_mask" , & object_set_mask );
		extern	void object_set_persistent(int objid, bool val);
		state.set( "object_set_persistent" , & object_set_persistent );
		extern	void object_set_solid(int objid, bool val);
		state.set( "object_set_solid" , & object_set_solid );
		extern	void object_set_sprite(int objid, int val);
		state.set( "object_set_sprite" , & object_set_sprite );
		extern	void object_set_visible(int objid, bool val);
		state.set( "object_set_visible" , & object_set_visible );
		extern	int object_get_depth(int objid);
		state.set( "object_get_depth" , & object_get_depth );
		extern	int object_get_mask(int objid);
		state.set( "object_get_mask" , & object_get_mask );
		extern	bool object_get_solid(int objid);
		state.set( "object_get_solid" , & object_get_solid );
		extern	int object_get_sprite(int objid);
		state.set( "object_get_sprite" , & object_get_sprite );
		extern	bool object_get_visible(int objid);
		state.set( "object_get_visible" , & object_get_visible );
		extern	bool object_is_ancestor(int objid, int acid);
		state.set( "object_is_ancestor" , & object_is_ancestor );
		extern	int resource_get_id(string name);
		state.set( "resource_get_id" , & resource_get_id );
		//extern	variant script_execute(int scr, variant arg0 = 0, variant arg1 = 0, variant arg2 = 0, variant arg3 = 0, variant arg4 = 0, variant arg5 = 0, variant arg6 = 0, variant arg7 = 0, variant arg8 = 0, variant arg9 = 0, variant arg10 = 0, variant arg11 = 0, variant arg12 = 0, variant arg13 = 0, variant arg14 = 14, variant arg15 = 0);
		//state.set( " script_execute" , & script_execute );
		extern	bool script_exists(int script);
		state.set( "script_exists" , & script_exists );
		extern	string object_get_name(int i);
		state.set( "object_get_name" , & object_get_name );
		extern	string sprite_get_name(int i);
		state.set( "sprite_get_name" , & sprite_get_name );
		extern	string background_get_name(int i);
		state.set( "background_get_name" , & background_get_name );
		extern	string font_get_name(int i);
		state.set( "font_get_name" , & font_get_name );
		extern	string timeline_get_name(int i);
		state.set( "timeline_get_name" , & timeline_get_name );
		extern	string path_get_name(int i);
		state.set( "path_get_name" , & path_get_name );
		extern	string sound_get_name(int i);
		state.set( "sound_get_name" , & sound_get_name );
		extern	string script_get_name(int i);
		state.set( "script_get_name" , & script_get_name );
		extern	string shader_get_name(int i);
		state.set( "shader_get_name" , & shader_get_name );
		extern void motion_set(int dir, cs_scalar newspeed);
		state.set( "motion_set" , &motion_set );
		extern void draw_sprite(int spr, int subimg, gs_scalar x, gs_scalar y, int color = 16777215, gs_scalar alpha = 1);
		state.set( "draw_sprite" , &draw_sprite );
		extern void draw_line(gs_scalar x1, gs_scalar y1, gs_scalar x2, gs_scalar y2);
		state.set( "draw_line" , &draw_line );
		state.set( "draw_string" , &draw_string );
		path = filepath;
		return;
	}
	void lua_stop(){
		path = "";
		//state.initialize(false);
		return;
	}
	void lua_add_var(string name, int var){
		if(state.getState() == nullptr){
			show_error("Lua was not initialized!", false);
		}
		const char *cname = name.c_str();
		state.set(cname, var);
		return;
	}
	void lua_add_var(string name, string var){
		if(state.getState() == nullptr){
			show_error("Lua was not initialized!", false);
		}
		const char *cname = name.c_str();
		state.set(cname, var);
		return;
	}
	/*variant lua_get_variable(string file, string variable){
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
	}*/
	void luaI_execute_file(){
		if(state.getState() == nullptr){
			show_error("Lua was not initialized!", false);
		}
		//lua::State state; //Creates a new Lua State
		//enigma::instance_t instance_create(int x,int y,int object);
		//setFunctions(state);
		try {
		state.doFile(path); //Executes the Lua File
		} catch(lua::LoadError er){
			show_error(er.what(), false);
		} catch(lua::RuntimeError er){
			show_error(er.what(), false);
		}
		return;
	}
	/*variant luaF_execute_file(string filepath,const std::function<int(int)> &f){
		//lua::State state; //Creates a new Lua State
		state.set("cfunction", f);
		state.doFile(filepath); //Executes the Lua File
		return 1;
	}
	variant luaF_execute_file(string filepath,const std::function<int(int, int)> &f){
		//lua::State state; //Creates a new Lua State
		state.set("cfunction", f);
		state.doFile(filepath); //Executes the Lua File
		return 1;
	}
	variant luaF_execute_file(string filepath,const std::function<int(int,int,int)> &f){
		//lua::State state; //Creates a new Lua State
		state.set("cfunction", f);
		state.doFile(filepath); //Executes the Lua File
		return 1;
	}
	variant luaF_execute_file(string filepath,const std::function<int(string)> &f){
		//lua::State state; //Creates a new Lua State
		state.set("cfunction", f);
		state.doFile(filepath); //Executes the Lua File
		return 1;
	}
	variant luaF_execute_file(string filepath,const std::function<int(string, string)> &f){
		//lua::State state; //Creates a new Lua State
		state.set("cfunction", f);
		state.doFile(filepath); //Executes the Lua File
		return 1;
	}*/
}