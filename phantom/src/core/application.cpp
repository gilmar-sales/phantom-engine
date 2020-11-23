#include <phpch.h>

#include "application.h"

namespace ph {
    Application::Application(std::string name, unsigned int height, unsigned int width)
        : m_layer_stack()
    {
        s_instance = this;

        m_window = new Window(name, height, width);
        m_window->set_event_callback(BIND_EVENT_FN(on_event));
    }

    void Application::run()
    {
        while(!glfwWindowShouldClose(&m_window->get_native_window())) {
            m_window->on_update();
        }
    }

    void Application::on_event(Event& event)
    {
       PH_CORE_INFO(event.to_string());
    }
}