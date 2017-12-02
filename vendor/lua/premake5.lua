project "lua"
	language "C++"
	kind "SharedLib"
	targetname "lua51_Win32"

	defines { "LUA_BUILD_AS_DLL" }

	vpaths {
		["Headers"] = "**.h",
		["Sources"] = "**.c",
		["*"] = "premake5.lua"
	}

	files {
		"premake5.lua",
		"**.c",
		"**.h",
	}
