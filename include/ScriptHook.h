/*****************************************************************************
*
*  PROJECT:     CIV5: Scripthook
*  LICENSE:     See LICENSE in the top level directory
*  PURPOSE:		Script hook core class
*
*****************************************************************************/
#pragma once
#include "ScriptHookEvents.h"

class ScriptHook
{
public:
	ScriptHook();

	inline ScriptHookEvents& GetEvents() { return _events; }

private:
	void InitConsole();

private:
	ScriptHookEvents _events;
};

ScriptHook* GetScriptHook();
