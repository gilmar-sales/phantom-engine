#pragma once

#include <core/layer.h>

#include "panels/hierarchy_panel.h"

namespace ph
{
    class EditorLayer : public Layer
    {
    public:
        EditorLayer();
        ~EditorLayer() = default;

        virtual void on_gui_render() override;
    private:
        HierarchyPanel* m_hierarchy_panel;
    };
    
}