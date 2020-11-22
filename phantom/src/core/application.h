#pragma once

#include "window.h"

namespace ph {
    class Application {
    public:
        Application(std::string name, unsigned int height, unsigned int width);
        ~Application() = default;

        virtual void on_update() = 0;
        virtual void on_event() = 0;

        void run();

        Window& get_window() { return *m_window; }

    private:
        Window* m_window;
    };

    Application* create_application();
}