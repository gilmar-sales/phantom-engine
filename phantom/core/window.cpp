#include "window.h"

namespace ph {
    Window::Window(const WindowData& data) {
        m_data = data;

        int success = glfwInit();

        if(!success) {
            std::cout << "Couldn't initialize GLFW!" << std::endl;
        }

        m_window = glfwCreateWindow(data.width, data.height, data.title.c_str());

        glfwMakeContextCurrent(m_window);
        
        if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            std::cout << "Couldn't initialize GLAD!" << std::endl;
        }
    }

    void Window::on_update() {
        glfwSwapBuffers(m_window);
    }
}