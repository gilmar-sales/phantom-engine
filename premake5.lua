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
    ["glfw"] = "%{wks.location}/phantom/libraries/glfw/include",
    ["glad"] = "%{wks.location}/phantom/libraries/glad/include",
    ["spdlog"] = "%{wks.location}/phantom/libraries/spdlog/include",
    ["imgui"] = "%{wks.location}/phantom/libraries/imgui",
    ["assimp"] = "%{wks.location}/phantom/libraries/assimp/include",
    ["ct-ecs"] = "%{wks.location}/phantom/libraries/ct-ecs/include"
}

include "phantom"
include "sandbox"

group "Libraries"
    include "phantom/libraries/glfw"
    include "phantom/libraries/glad"
