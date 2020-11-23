#pragma once

#define IMGUI_DEFINE_MATH_OPERATORS
#include <imgui.h>
#include <imgui_internal.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace ph
{
	void StylePhantomLight(ImGuiStyle* dst = nullptr);
	void StylePhantomDark(ImGuiStyle* dst = nullptr);
}