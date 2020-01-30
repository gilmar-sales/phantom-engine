workspace "phantom-engine"
    architecture "x86_64"
    
    configurations {
		"Debug",
		"Release",
		"Dist"
    }
    
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["glfw"] = "phantom/libraries/glfw/include"
IncludeDir["glad"] = "phantom/libraries/glad/include"
IncludeDir["spdlog"] = "phantom/libraries/spdlog/include"

group "Dependencies"
    include "phantom/libraries/glfw"
    include "phantom/libraries/glad"
    include "phantom/libraries/spdlog"

group ""

project "phantom"
    kind "StaticLib"
    language "C++"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs {
		"%{prj.name}/src",
		"%{IncludeDir.glfw}",
		"%{IncludeDir.glad}",
		"%{IncludeDir.spdlog}"
    }
    
    links { 
		"glfw",
		"glad",
		"spdlog"
    }
    
    filter "toolset:msvc"
        links {
            "opengl32.lib"
        }

    filter "toolset:gcc"
        links {
            "GL"
        }

    filter "configurations:Debug"
		defines "PH_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "PH_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "PHs_DIST"
		runtime "Release"
		optimize "on"