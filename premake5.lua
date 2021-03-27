workspace "Hgenx"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Hgenx/vendor/GLFW/include"

include "Hgenx/vendor/GLFW"

project "Hgenx"
	location "HGenx"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hgpch.h"
	pchsource "Hgenx/src/hgpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
			systemversion "latest"

	defines
	{
		"HG_PLATFORM_WINDOWS",
		"HG_BUILD_DLL"
	}
			
	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}

	filter "configurations:Debug"
		defines "HG_DEBUG"
		buildoptions "/MDd"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HG_RELEASE"
		buildoptions "/MD"
		runtime "Release"
		optimize "on"	

	filter "configurations:Dist"
		defines "HG_DIST"
		buildoptions "/MD"
		runtime "Release"
		optimize "on"	


	project "Sandbox"
		location "Sandbox"
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"HGenx/vendor/spdlog/include",
		"Hgenx/src",
		"Hgenx/vendor"
	}

	links
	{
		"Hgenx"
	}

	filter "system:windows"
			systemversion "latest"

	defines
	{
		"HG_PLATFORM_WINDOWS",
	}

	filter "configurations:Debug"
		defines "HG_DEBUG"
		buildoptions "/MDd"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HG_RELEASE"
		buildoptions "/MD"
		runtime "Release"
		optimize "on"	

	filter "configurations:Dist"
		defines "HG_DIST"
		buildoptions "/MD"
		runtime "Release"
		optimize "on"	