#pragma once

#include <core/layer.h>

namespace ph
{
    class GUILayer : public Layer
    {
    private:
        bool m_block_events = true;
        float m_time = 0.9f;
    public:
        GUILayer();
        ~GUILayer() = default;

        virtual void on_attach() override;
        virtual void on_detach() override;
        virtual void on_event(Event& event) override;

        void begin();
        void end();

        void block_events(bool block) { m_block_events = block; }
    };
}