#include "editor_layer.h"

#include <imgui.h>
#include <core/application.h>

#include <gui/styles/styles.h>
#include <gui/extensions/extensions.h>

namespace ph
{
    EditorLayer::EditorLayer() : Layer("EditorLayer")
    {
        m_hierarchy_panel = new HierarchyPanel();
    }

    void EditorLayer::on_gui_render()
    {
        bool p_open;
        static bool preferences_open = false;
        ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
        static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

        ImGuiViewport* viewport = ImGui::GetMainViewport();
        
        ImGui::SetNextWindowPos(viewport->GetWorkPos());
        ImGui::SetNextWindowSize(viewport->GetWorkSize());
        ImGui::SetNextWindowViewport(viewport->ID);


        window_flags    |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse 
                        | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove
                        | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

        ImGui::Begin("DockSpace", &p_open, window_flags);


        // DockSpace
        ImGuiIO& io = ImGui::GetIO();
        if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
        {
            ImGuiID dockspace_id = ImGui::GetID("MainDockSpace");
            ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
        }

        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                if (ImGui::MenuItem("New Project...", "Ctrl+N")) { /* Do stuff */ }
                ImGui::Separator();
                if (ImGui::MenuItem("Open Project...", "Ctrl+O")) { /* Do stuff */ }
                if (ImGui::MenuItem("Open Recent")) { /* Do stuff */ }
                ImGui::Separator();
                if (ImGui::MenuItem("Save", "Ctrl+S"))   { /* Do stuff */ }
                if (ImGui::MenuItem("Save As...", "Ctrl+Shift+S"))   { /* Do stuff */ }
                ImGui::Separator();
                if (ImGui::MenuItem("Close Project", "Ctrl+W"))  { }
                if (ImGui::MenuItem("Close Phantom", "Alt+F4")) 
                { 
                    glfwSetWindowShouldClose(Application::get().get_window().get_native_window(), 1);
                }
                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Edit"))
            {
                if (ImGui::MenuItem("Undo...", "Ctrl+N")) { /* Do stuff */ }
                if (ImGui::MenuItem("Redo...", "Ctrl+O")) { /* Do stuff */ }
                ImGui::Separator();
                if (ImGui::MenuItem("Cut", "Ctrl+X")) { /* Do stuff */ }
                if (ImGui::MenuItem("Copy", "Ctrl+C"))   { /* Do stuff */ }
                if (ImGui::MenuItem("Paste", "Ctrl+V"))   { /* Do stuff */ }
                ImGui::Separator();
                if (ImGui::MenuItem("Preferences...", "Ctrl+,"))
                {
                    preferences_open = true;
                }
                ImGui::EndMenu();
            }

            if (preferences_open) {

                ImGui::Begin("Preferences", &preferences_open, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize);

                ToggleButton("Toggle dark mode", &m_enable_dark_theme);

                if (m_enable_dark_theme)
                    StylePhantomDark();
                else 
                    StylePhantomLight();

                ImGui::End();
            }

            if (ImGui::BeginMenu("Entity"))
            {
                if (ImGui::MenuItem("Create Empty")) { /* Do stuff */ }
                if (ImGui::BeginMenu("Create Geometry")) 
                {
                    if (ImGui::MenuItem("Cube")) { /* Do stuff */ }
                    if (ImGui::MenuItem("Sphere")) { /* Do stuff */ }
                    if (ImGui::MenuItem("Capsule")) { /* Do stuff */ }
                    ImGui::EndMenu();
                } 
                
                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Component"))
            {
                if (ImGui::BeginMenu("Enable Component")) 
                {
                    if (ImGui::MenuItem("Camera")) { /* Do stuff */ }
                    if (ImGui::MenuItem("Transform")) { /* Do stuff */ }
                    if (ImGui::MenuItem("RigidBody")) { /* Do stuff */ }
                    ImGui::EndMenu();
                } 
                
                ImGui::EndMenu();
            }
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

            ImGui::EndMenuBar();

        }

        ImGui::Begin("Scene");
        ImGui::End();
        ImGui::Begin("Game");
        ImGui::End();

        ImGui::Begin("Assets");
        ImGui::End();

        ImGui::End();

        static bool stats = true;

        static ImGuiDockNodeFlags stats_flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize
            | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoDocking;

        m_hierarchy_panel->on_gui_render();
    }
}