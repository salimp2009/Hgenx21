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

project "Hgenx"
	location "HGenx"
	kind "SharedLib"
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
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
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
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HG_RELEASE"
		runtime "Release"
		optimize "on"	

	filter "configurations:Dist"
		defines "HG_DIST"
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
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HG_RELEASE"
		runtime "Release"
		optimize "on"	

	filter "configurations:Dist"
		defines "HG_DIST"
		runtime "Release"
		optimize "on"	