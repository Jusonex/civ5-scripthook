workspace "civ5_scripthook"
	configurations { "Debug", "Release" }
	location "build"
	targetdir "bin"
	startproject "civ5_scripthook"

	defines { "_CRT_SECURE_NO_WARNINGS", "WIN32_LEAN_AND_MEAN" }

	filter "configurations:Debug"
		targetsuffix "_d"

	filter "configurations:Release"
		optimize "Full"

	filter {}
	project "civ5_scripthook"
		language "C++"
		cppdialect "C++17"
		kind "ConsoleApp"

		includedirs { "include" }

		files {
			"premake5.lua",

			"include/**.h",
			"src/**.cpp",
		}

	-- Dependencies
	group "vendor"
	include "vendor/lua"
