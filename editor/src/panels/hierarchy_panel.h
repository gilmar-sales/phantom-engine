#pragma once

#include <memory>

#include <core/scene.h>
#include <ecs/ecs.hpp>

namespace ph
{
    class HierarchyPanel
	{
	public:
		HierarchyPanel(std::shared_ptr<Scene> scene);
		//HierarchyPanel(const Ref<Scene>& scene);

		//void SetContext(const Ref<Scene>& scene);

		void on_gui_render();
	private:
		void draw_entity_node(unsigned entity);
		//void DrawComponents(Entity entity);

		std::shared_ptr<Scene> m_scene;
		unsigned m_SelectionContext;
	};
} // namespace ph
