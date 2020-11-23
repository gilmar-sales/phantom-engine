#pragma once

namespace ph
{
    class HierarchyPanel
	{
	public:
		HierarchyPanel() = default;
		//HierarchyPanel(const Ref<Scene>& scene);

		//void SetContext(const Ref<Scene>& scene);

		void on_gui_render();
	private:
		//void DrawEntityNode(Entity entity);
		//void DrawComponents(Entity entity);

		//Ref<Scene> m_Context;
		//Entity m_SelectionContext;
	};
} // namespace ph
