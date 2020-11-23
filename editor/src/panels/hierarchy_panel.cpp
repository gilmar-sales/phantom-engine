#include "hierarchy_panel.h"

#include <imgui.h>

namespace ph
{
    void HierarchyPanel::on_gui_render()
	{
		ImGui::Begin("Hierarchy");

		/*
        m_Context->m_Registry.each([&](auto entityID)
		{
			Entity entity{ entityID , m_Context.get() };
			DrawEntityNode(entity);
		});

		if (ImGui::IsMouseDown(0) && ImGui::IsWindowHovered())
			m_SelectionContext = {};
        */

		// context menu
		if (ImGui::BeginPopupContextWindow())
		{
			if (ImGui::MenuItem("Empty entity")) { /* Do stuff */ }
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
	}
} // namespace ph
