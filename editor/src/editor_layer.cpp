#include "editor_layer.h"

#include <imgui.h>
#include <core/application.h>

#include <gui/styles/styles.h>
#include <gui/extensions/extensions.h>

namespace ph
{
    EditorLayer::EditorLayer(std::shared_ptr<ph::Scene> scene) : Layer("EditorLayer")
    {
        m_hierarchy_panel = std::make_shared<ph::HierarchyPanel>(scene);

        FramebufferSpecification spec 
        {
            200,300
        };

        m_scene_frame = Framebuffer::create(spec);
    }

    void EditorLayer::on_gui_render()
    {
        static ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
        static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

        ImGuiViewport* viewport = ImGui::GetMainViewport();
        
        ImGui::SetNextWindowPos(viewport->GetWorkPos());
        ImGui::SetNextWindowSize(viewport->GetWorkSize());
        ImGui::SetNextWindowViewport(viewport->ID);

        window_flags    |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse 
                        | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove
                        | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

        static bool preferences_open = false;
        static ImGuiIO& io = ImGui::GetIO();

        if (ImGui::Begin("DockSpace", nullptr, window_flags))
        {
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
                    if (ImGui::MenuItem("Save", "Ctrl+S")) { /* Do stuff */ }
                    if (ImGui::MenuItem("Save As...", "Ctrl+Shift+S")) { /* Do stuff */ }
                    ImGui::Separator();
                    if (ImGui::MenuItem("Close Project", "Ctrl+W")) {}
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
                    if (ImGui::MenuItem("Copy", "Ctrl+C")) { /* Do stuff */ }
                    if (ImGui::MenuItem("Paste", "Ctrl+V")) { /* Do stuff */ }
                    ImGui::Separator();
                    if (ImGui::MenuItem("Preferences...", "Ctrl+,"))
                    {
                        preferences_open = true;
                    }

                    ImGui::EndMenu();
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

            if (preferences_open) {

                ImGui::Begin("Preferences", &preferences_open, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize);

                ToggleButton("Toggle dark mode", &m_enable_dark_theme);

                if (m_enable_dark_theme)
                    StylePhantomDark();
                else
                    StylePhantomLight();

                ImGui::End();
            }

            ImGui::Begin("Scene");
                ImVec2 avail_size = ImGui::GetContentRegionAvail();
                m_scene_frame->resize(avail_size.x, avail_size.y);
                m_scene_frame->bind();
                glClear(GL_COLOR_BUFFER_BIT);
                m_scene_frame->unbind();

                ImGui::Image((void*)(intptr_t)m_scene_frame->get_color_attachment_renderer_id(), avail_size);
            ImGui::End();

            ImGui::Begin("Game");
            ImGui::End();

            ImGui::Begin("Assets");
            ImGui::End();

        ImGui::End(); // DockSpace
        }


        m_hierarchy_panel->on_gui_render();
    }
}