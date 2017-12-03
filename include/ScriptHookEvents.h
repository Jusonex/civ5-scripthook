#pragma once
#include "Event.h"

#include <string>

struct lua_State;

struct ScriptHookEvents
{
	// Called when a new Lua virtual machine is created
	// Parameters: luaVM
	Event<lua_State*> OnVmCreate;

	// Called when a script file is loaded
	// Parameters: luaVM, content, chunk name
	Event<lua_State*, const std::string&, const std::string&> OnScriptLoad;
};
