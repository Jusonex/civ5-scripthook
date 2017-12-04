/*****************************************************************************
*
*  PROJECT:     CIV5: Scripthook
*  LICENSE:     See LICENSE in the top level directory
*  PURPOSE:     Script hook core class
*
*****************************************************************************/
#include "ScriptHook.h"
#include "Package.h"

#include <iostream>
#include <fs.h>
#include <Windows.h>

ScriptHook::ScriptHook()
{
	// Initialise the console
	InitConsole();

	// Add some events for testing
	GetEvents().OnVmCreate += [this](lua_State* luaVM) {
		std::cout << "OnVmCreated called" << std::endl;
	};
	GetEvents().OnScriptLoad += [this](lua_State* luaVM, const std::string& content, const std::string& chunkName) {
		if (chunkName == "Assets\\UI\\InGame\\LeaderHead\\DiscussLeader.lua")
		{
			GetEvents().OnGameStart(luaVM);
		}

		std::cout << "OnScriptLoad called (chunk name: " << chunkName << ")" << std::endl;
	};
	GetEvents().OnGameStart += [this](lua_State* luaVM) {
		// Load packages
		LoadPackages(luaVM);
	};
}

void ScriptHook::InitConsole()
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	SetConsoleTitleA("CIV5: Scripthook");
}

void ScriptHook::LoadPackages(lua_State* luaVM)
{
	for (auto& packagePath : fs::directory_iterator(Package::GetPackagesPath()))
	{
		// Ignore non-directories
		if (!fs::is_directory(packagePath))
			continue;

		// Construct package
		auto package = std::make_unique<Package>(packagePath.path().filename().generic_string());
		std::cout << "Loading package: " << package->GetName() << std::endl;
		package->Load(luaVM);

		// Transfer ownership to package list
		_packages.push_back(std::move(package));
	}
}


ScriptHook* GetScriptHook()
{
	static ScriptHook* scriptHook = new ScriptHook();
	return scriptHook;
}
