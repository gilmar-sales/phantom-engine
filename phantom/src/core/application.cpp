#include "application.h"

namespace ph {
    Application::Application(std::string name, unsigned int height, unsigned int width) {
        WindowData data = {name, height, width};
        m_window = new Window(data);
    }

    void Application::run() {
        while(!glfwWindowShouldClose(&m_window->get_native_window())) {
            m_window->on_update();
        }
    }
}