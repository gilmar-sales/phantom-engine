#pragma once

#include <core/layer.h>


namespace ph
{
    class EditorLayer : public Layer
    {
    public:
        EditorLayer();
        ~EditorLayer() = default;

        virtual void on_gui_render() override;
    };
    
}