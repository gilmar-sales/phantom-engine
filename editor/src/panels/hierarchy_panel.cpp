#include "hierarchy_panel.h"

#include <imgui.h>

namespace ph
{
	static char entity_name[32] = "Empty";

	HierarchyPanel::HierarchyPanel(std::shared_ptr<Scene> scene) : m_scene(scene)
	{

	}

	int entity_name_callback(ImGuiInputTextCallbackData* data)
	{
		strcpy(entity_name, data->Buf);

		return 0;
	}

    void HierarchyPanel::on_gui_render()
	{
		ImGui::Begin("Hierarchy");


		if (ImGui::IsMouseDown(0) && ImGui::IsWindowHovered())
		{
			m_SelectionContext = 999999;
			PH_CORE_INFO("select entity {}", m_SelectionContext);
		}

        m_scene->m_manager.for_each([&](auto entityID)
		{
			draw_entity_node(entityID);
		});

		// context menu
		if (ImGui::BeginPopupContextWindow(0, 1, false))
		{
			if (ImGui::MenuItem("Empty entity"))
			{
				auto entity = m_scene->m_manager.create_entity();

				auto& name = m_scene->m_manager.add_component<ecs::NameComponent>(entity);
				name.name = entity_name;
				ImGui::BulletText("Return to input text into a widget.");
				if (!ImGui::IsPopupOpen("popup"))
					ImGui::OpenPopup("popup");

			}

			if (ImGui::BeginMenu("3D Entity"))
			{
				if (ImGui::MenuItem("Cube")) { /* Do stuff */ }
				if (ImGui::MenuItem("Sphere")) { /* Do stuff */ }
				if (ImGui::MenuItem("Capsule")) { /* Do stuff */ }
				ImGui::EndMenu();
			}

			if (ImGui::MenuItem("Camera")) { /* Do stuff */ }
			if (ImGui::MenuItem("Terrain")) { /* Do stuff */ }


			ImGui::EndPopup();
		}

		ImGui::End();

		ImGui::Begin("Properties");
        /*
		if (m_SelectionContext)
			DrawComponents(m_SelectionContext);
        */

		ImGui::End();
		if (ImGui::BeginPopup("Popup", 0))
		{
			ImGuiTreeNodeFlags flags1 = ImGuiTreeNodeFlags_OpenOnArrow;
			flags1 |= ImGuiTreeNodeFlags_SpanAvailWidth;
			flags1 |= ImGuiTreeNodeFlags_AllowItemOverlap;
			ImGui::TreeNodeEx((void*)(uint64_t)(uint32_t)200, flags1, "Node test");
			
		ImGui::EndPopup();
		}
	}

	void HierarchyPanel::draw_entity_node(unsigned entity)
	{
		auto& tag = m_scene->m_manager.get_component<ecs::NameComponent>(entity).name;
		
		ImGuiTreeNodeFlags flags = ((m_SelectionContext == entity) ? ImGuiTreeNodeFlags_Selected : 0) | ImGuiTreeNodeFlags_OpenOnArrow;
		flags |= ImGuiTreeNodeFlags_SpanAvailWidth;
		bool opened = ImGui::TreeNodeEx((void*)(uint64_t)(uint32_t)entity, flags, tag.c_str());
		if (ImGui::IsItemClicked() | ImGui::IsItemClicked(1))
		{
			m_SelectionContext = entity;
			PH_CORE_INFO("select entity {}", m_SelectionContext);
		}

		bool entityDeleted = false;
		if (ImGui::BeginPopupContextItem())
		{
			if (ImGui::MenuItem("Delete Entity"))
				entityDeleted = true;
			
			if (ImGui::MenuItem("Add transform"))
			{
				m_scene->m_manager.add_component<ecs::TransformComponent>(entity);
			}

			ImGui::EndPopup();
		}

		if (opened)
		{
			ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_SpanAvailWidth;
			bool opened = ImGui::TreeNodeEx((void*)9817239, flags, tag.c_str());
			if (opened)
				ImGui::TreePop();
			ImGui::TreePop();
		}

		if (entityDeleted)
		{
			m_scene->m_manager.destroy_entity(entity);
			if (m_SelectionContext == entity)
				m_SelectionContext = {};
		}
	}
} // namespace ph
