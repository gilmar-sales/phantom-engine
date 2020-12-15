
project "editor"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "src/**.h",
        "src/**.cpp",
    }

    includedirs {
        "%{wks.location}/phantom/src",
        "%{IncludeDir.glfw}",
        "%{IncludeDir.glad}",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.imgui}",
        "%{IncludeDir.glm}"
    }

    links {
        "phantom",
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

    filter "system:linux" 
        links {
            "dl",
            "X11",
            "pthread"
        }

    filter "system:macosx"
        links {
            "Cocoa.framework",
            "IOKit.framework"
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