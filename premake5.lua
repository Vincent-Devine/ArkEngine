workspace "ArkEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "ArkEngine"
	location "ArkEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Sources/**.cpp",
		"%{prj.name}/Headers/**.hpp",
		"%{prj.name}/Headers/**.h"
	}

	includedirs
	{
		"%{prj.name}/ThirdParty/",
		"%{prj.name}/Headers/",
		"%{prj.name}/Headers/"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ARK_PLATFORM_WINDOWS",
			"ARK_BUILD_DLL",
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ARK_ENGINE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ARK_ENGINE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ARK_ENGINE_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox" 
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Sources/**.cpp",
		"%{prj.name}/Headers/**.hpp",
		"%{prj.name}/Headers/**.h",
	}

	includedirs
	{
		"ArkEngine/ThirdParty/",
		"ArkEngine/Headers/Ark",
		"ArkEngine/Headers"
	}

	links
	{
		"ArkEngine"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ARK_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "ARK_ENGINE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ARK_ENGINE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ARK_ENGINE_DIST"
		optimize "On"
