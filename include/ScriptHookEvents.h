/*****************************************************************************
*
*  PROJECT:     CIV5: Scripthook
*  LICENSE:     See LICENSE in the top level directory
*  PURPOSE:	    Script hook events class
*
*****************************************************************************/
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

	// Called when the LuaVM is ready (i.e. functions and classes are available)
	// Parameters: luaVM
	Event<lua_State*> OnGameStart;
};
