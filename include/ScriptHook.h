/*****************************************************************************
*
*  PROJECT:     CIV5: Scripthook
*  LICENSE:     See LICENSE in the top level directory
*  PURPOSE:     Script hook core class
*
*****************************************************************************/
#pragma once
#include "ScriptHookEvents.h"

#include <vector>
#include <memory>

class Package;

class ScriptHook
{
public:
	ScriptHook();

	inline ScriptHookEvents& GetEvents() { return _events; }

private:
	void InitConsole();

	void LoadPackages(lua_State* luaVM);

private:
	ScriptHookEvents _events;

	std::vector<std::unique_ptr<Package>> _packages;
};

ScriptHook* GetScriptHook();
