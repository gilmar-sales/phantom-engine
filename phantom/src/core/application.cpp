#include <phpch.h>

#include "application.h"

namespace ph {
    Application* Application::s_instance = nullptr;

    Application::Application(std::string name, unsigned int height, unsigned int width)
        : m_layer_stack()
    {
        s_instance = this;

        m_window = new Window(name, height, width);
        m_window->set_event_callback(BIND_EVENT_FN(on_event));

        m_gui_layer = new GUILayer();
        push_overlay(m_gui_layer);
    }

    void Application::run()
    {
        while(!glfwWindowShouldClose(m_window->get_native_window())) {
            glClear(GL_COLOR_BUFFER_BIT);
            
            m_gui_layer->begin();
            {

                for (Layer* layer : m_layer_stack)
                    layer->on_gui_render();
            }
            m_gui_layer->end();

            m_window->on_update();
        }
    }

    void Application::on_event(Event& event)
    {
       //PH_CORE_INFO(event.to_string());

       for (auto it = m_layer_stack.rbegin(); it != m_layer_stack.rend(); ++it)
       {
           if (event.Handled)
               break;
           (*it)->on_event(event);
       }
    }

    void Application::push_layer(Layer* layer)
    {
        m_layer_stack.push_layer(layer);
        layer->on_attach();
    }

    void Application::push_overlay(Layer* layer)
    {
        m_layer_stack.push_overlay(layer);
        layer->on_attach();
    }
}