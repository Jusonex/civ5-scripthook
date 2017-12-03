/*****************************************************************************
*
*  PROJECT:     CIV5: Scripthook
*  LICENSE:     See LICENSE in the top level directory
*  PURPOSE:     Package class
*
*****************************************************************************/
#pragma once
#include <string>
#include <vector>
#include <fs.h>

struct lua_State;

class Package
{
public:
	Package(const std::string& name);

	void Load(lua_State* luaVM);

	inline std::string GetName() { return _name; }
	fs::path GetAbsolutePath();

	static fs::path GetPackagesPath();

protected:
	bool ReadMetadata();
	void RegisterFunctions(lua_State* luaVM);

private:
	std::string _name;
	std::vector<std::string> _scripts;
};
