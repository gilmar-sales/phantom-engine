#include <phpch.h>
#include "gui_layer.h"

#include <imgui.h>
#include <examples/imgui_impl_glfw.h>
#include <examples/imgui_impl_opengl3.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <core/application.h>
#include <core/log.h>

//#include "styles/styles.h"

namespace ph
{
	GUILayer::GUILayer() : Layer("GUILayer") {}

	void GUILayer::on_attach()
	{
		// Setup Dear ImGui context
		IMGUI_CHECKVERSION();
		PH_CORE_INFO("Check imgui version");
		ImGui::CreateContext();
		PH_CORE_INFO("ImGui::CreateContext");
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
		//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
		//io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoTaskBarIcons;
		//io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoMerge;

		io.Fonts->AddFontFromFileTTF("font.ttf", 15);

		// Setup Dear ImGui style

		//ImGui::StyleColorsDark();
		//ImGui::StyleColorsClassic();
		StylePhantomDark();

		// When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
		ImGuiStyle& style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

		style.WindowRounding = 4.0f;
		style.WindowBorderSize = 0.0f;
		style.GrabRounding = 2.0f;

		style.AntiAliasedLines = true;
		style.AntiAliasedFill = true;
		style.IndentSpacing = 22;

		style.ChildRounding = 3.0f;
		style.ChildBorderSize = 0.0f;

		style.ScrollbarRounding = 3.0f;
		style.ScrollbarSize = 16;
		style.ScrollbarRounding = 3;

		style.ItemSpacing.x = 10;
		style.ItemSpacing.y = 4;

		style.TabBorderSize = 0.0f;
		style.PopupBorderSize = 0.0f;

		style.FramePadding.x = 6;
		style.FramePadding.y = 4;
		style.FrameRounding = 3.0f;
		style.FrameBorderSize = 0.0f;

		style.Alpha = 1.0f;

		Application& app = Application::get();
		GLFWwindow* window = static_cast<GLFWwindow*>(app.get_window().get_native_window());

		// Setup Platform/Renderer bindings
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 410");

	}

	void GUILayer::on_detach()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void GUILayer::on_event(Event& event)
	{
		if (m_block_events)
		{
			ImGuiIO& io = ImGui::GetIO();
			event.Handled |= event.is_in_category(EventCategoryMouse) & io.WantCaptureMouse;
			event.Handled |= event.is_in_category(EventCategoryKeyboard) & io.WantCaptureKeyboard;
		}
	}

	void GUILayer::begin()
	{

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void GUILayer::end()
	{

		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::get();
		io.DisplaySize = ImVec2((float)app.get_window().get_width(), (float)app.get_window().get_height());

		// Rendering
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}
	}
}