#pragma once

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace ph {

    struct WindowData {
        std::string title;
        unsigned width, height;
        bool v_sync;
    };

    class Window {
    public:
        Window(const WindowData& data);
        ~Window();

        void on_update();

        inline unsigned get_width() { return m_data.width; }
        inline unsigned get_height() { return m_data.height; }

        GLFWwindow& get_native_window() { return *m_window; }
    private:
        GLFWwindow* m_window;
        WindowData m_data;
    };
}