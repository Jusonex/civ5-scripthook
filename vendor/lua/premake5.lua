project "lua_patched"
	language "C++"
	kind "SharedLib"
	targetname "lua51_Win32"

	defines { "LUA_BUILD_AS_DLL", "SCRIPTHOOK_PATCHES_ENABLED" }

	includedirs { "../include" }
	forceincludes { "scripthook_calls.h" }
	links { "civ5_scripthook" }

	vpaths {
		["Headers"] = "**.h",
		["Sources"] = "**.c",
		["*"] = "premake5.lua"
	}

	files {
		"premake5.lua",
		"**.c",
		"**.h",

		"scripthook_calls.cpp"
	}

project "lua_library"
	language "C++"
	kind "StaticLib"
	targetname "lua_library"

	includedirs { "../include" }
	forceincludes { "scripthook_calls.h" }

	vpaths {
		["Headers"] = "**.h",
		["Sources"] = "**.c",
		["*"] = "premake5.lua"
	}

	files {
		"premake5.lua",
		"**.c",
		"**.h"
	}
