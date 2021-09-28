#pragma once

#include <core/layer.h>

#include "panels/hierarchy_panel.h"
#include <platform/opengl/opengl_frame_buffer.h>

namespace ph
{

class EditorLayer : public Layer
{
  public:
    EditorLayer(std::shared_ptr<ph::Scene> hierarchy_panel);
    ~EditorLayer() = default;

    virtual void on_gui_render() override;

  private:
    std::shared_ptr<ph::HierarchyPanel> m_hierarchy_panel;
    std::shared_ptr<Framebuffer> m_scene_frame;
    bool m_enable_dark_theme = true;
};

} // namespace ph