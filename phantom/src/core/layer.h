#pragma once

#include <events/event.h>

namespace ph
{
    class Layer
    {
    private:
        std::string m_name;
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer() = default;

        virtual void on_attach() {}
        virtual void on_detach() {}
        virtual void on_gui_render() {}
        virtual void on_event(Event& event) {}
        virtual void on_update() {}

        const std::string& get_name() const { return m_name; }
    };

}