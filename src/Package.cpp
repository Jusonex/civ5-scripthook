/*****************************************************************************
*
*  PROJECT:     CIV5: Scripthook
*  LICENSE:     See LICENSE in the top level directory
*  PURPOSE:     Package class
*
*****************************************************************************/
#include <Package.h>

#include <fstream>
#include <stdexcept>
#include <iostream>
#include <json.hpp>

extern "C"
{
	#include <lua/lua.h>
	#include <lua/lauxlib.h>
}

const char* kPackagePath = "ScriptPackages";
const char* kPackageMetaFile = "package.json";

Package::Package(const std::string& name) : _name(name)
{
}

void Package::Load(lua_State* luaVM)
{
	if (!ReadMetadata())
	{
		// TODO: Print error
		return;
	}

	// Register custom functions
	RegisterFunctions(luaVM);

	// Actually load scripts now
	for (auto& scriptPath : _scripts)
	{
		// TODO: We need to use luaL_loadbuffer for unicode support
		auto absolutePath = GetAbsolutePath().append(scriptPath).generic_string();
		if (luaL_dofile(luaVM, absolutePath.c_str()) != 0)
		{
			std::cout << "SCRIPT ERROR: " << lua_tostring(luaVM, -1) << std::endl;
		}
	}
}

fs::path Package::GetAbsolutePath()
{
	return fs::path{ kPackagePath }.append(_name);
}

fs::path Package::GetPackagesPath()
{
	return fs::path{ kPackagePath };
}

bool Package::ReadMetadata()
{
	try
	{
		std::ifstream configFile{ GetAbsolutePath().append(kPackageMetaFile) };
		nlohmann::json config;
		configFile >> config;

		for (auto& scriptPath : config["scripts"])
		{
			_scripts.push_back(scriptPath.get<std::string>());
		}

		return true;
	}
	catch (std::exception&)
	{
		// TODO
	}

	return false;
}

void Package::RegisterFunctions(lua_State* luaVM)
{
	lua_register(luaVM, "hook_print", [](lua_State* luaVM) -> int {
		if (lua_type(luaVM, 1) == LUA_TSTRING)
		{
			std::printf("%s\n", lua_tostring(luaVM, 1));
			lua_pushboolean(luaVM, true);
			return 1;
		}

		lua_pushboolean(luaVM, false);
		return 1;
	});
}
