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
