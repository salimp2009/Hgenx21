workspace "Hgenx"
	architecture "x64"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

project "Hgenx"
	location "HGenx"
	kind "SharedLib"
	language "C++"

	target

HG_PLATFORM_WINDOWS;HG_BUILD_DLL;