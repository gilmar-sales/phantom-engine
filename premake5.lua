workspace "phantom-engine"
    project "phantom"
        kind "StaticLib"
        language "C++"
        staticruntime "on"
    
        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        file {
            
        }