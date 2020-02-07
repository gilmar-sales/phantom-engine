workspace "phantom-engine"
    architecture "x86_64"
	startproject "sandbox"

    
    configurations {
		"Debug",
		"Release",
		"Dist"
    }
    
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {
    ["glfw"] = "phantom/libraries/glfw/include",
    ["glad"] = "phantom/libraries/glad/include"

}
--IncludeDir["spdlog"] = "phantom/libraries/spdlog/include"

group "Dependencies"
    include "phantom/libraries/glfw"
    include "phantom/libraries/glad"

group ""

project "phantom"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "%{prj.name}/src/phpch.h"
    pchsource "%{prj.name}/src/phpch.cpp"
    
    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs {
		"%{prj.name}",
		"%{prj.name}/src",
		"%{IncludeDir.glfw}",
		"%{IncludeDir.glad}",
		"phantom/libraries/spdlog/include"
    }
    
    links { 
		"glfw",
		"glad"
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
		defines "PH_DIST"
		runtime "Release"
        optimize "on"

project "sandbox"
    location "sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs {
		"phantom",
		"phantom/src",
		"%{IncludeDir.glfw}",
		"%{IncludeDir.glad}",
		"phantom/libraries/spdlog/include"
    }

    links {
        "phantom",
		"glfw",
        "glad",
        "GL"
    }

    filter "system:linux" 
        links {
            "dl",
            "X11",
            "pthread"
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
		defines "PH_DIST"
		runtime "Release"
        optimize "on"