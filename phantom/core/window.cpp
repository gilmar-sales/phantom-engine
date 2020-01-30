#include "window.h"

namespace ph {
    Window::Window(const WindowData& data) {
        m_data = data;

        int success = glfwInit();

        if(!success) {
            std::cout << "Couldn't initialize GLFW!" << std::endl;
        }

        if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            std::cout << "Couldn't initialize GLAD!" << std::endl;
        }
    }
}