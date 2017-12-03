project "lua"
	language "C++"
	kind "SharedLib"
	targetname "lua51_Win32"

	defines { "LUA_BUILD_AS_DLL" }

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
