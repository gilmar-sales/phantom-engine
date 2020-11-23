project "phantom"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "phpch.h"
    pchsource "src/phpch.cpp"

    files {
        "src/**.h",
        "src/**.cpp",
    }

    includedirs {
        "src",
        "%{IncludeDir.glfw}",
        "%{IncludeDir.glad}",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.imgui}",
    }

    links { 
        "glfw",
        "glad",
        "imgui"
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
