#pragma once

#include <functional>

#include "window.h"
#include "layer_stack.h"

#include <gui/gui_layer.h>

int main(int argc, char** argv);

namespace ph
{
    #define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    class Application
    {
    public:
        Application(std::string name, unsigned int height, unsigned int width);
        ~Application() = default;

        virtual void on_update() = 0;

        void on_event(Event& e);
        void run();

        void push_layer(Layer* layer);
        void push_overlay(Layer* layer);

        Window& get_window() { return *m_window; }

        static Application& get() { return *s_instance; }

    private:
        Window* m_window;
        GUILayer* m_gui_layer;
        LayerStack m_layer_stack;

        static Application* s_instance;
        friend int ::main(int argc, char** argv);
    };

    Application* create_application();
}