/*****************************************************************************
*
*  PROJECT:     CIV5: Scripthook
*  LICENSE:     See LICENSE in the top level directory
*  PURPOSE:		Script hook core class
*
*****************************************************************************/
#include "ScriptHook.h"

#include <iostream>
#include <Windows.h>

ScriptHook::ScriptHook()
{
	// Initialise the console
	InitConsole();

	// Add some events for testing
	GetEvents().OnVmCreate += [](lua_State*) {
		std::cout << "OnVmCreated called" << std::endl;
	};
	GetEvents().OnScriptLoad += [](lua_State*, const std::string& content, const std::string& chunkName) {
		std::cout << "OnScriptLoad called (chunk name: " << chunkName << ")" << std::endl;
	};
}

void ScriptHook::InitConsole()
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	SetConsoleTitleA("CIV5: Scripthook");
}


ScriptHook* GetScriptHook()
{
	static ScriptHook* scriptHook = new ScriptHook();
	return scriptHook;
}
