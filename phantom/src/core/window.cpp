#include "window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace ph {
    Window::Window(const WindowData& data) {
        m_data = data;

        int success = glfwInit();

        if(!success) {
            std::cout << "Couldn't initialize GLFW!" << std::endl;
        }

        m_window = glfwCreateWindow(data.width, data.height, data.title.c_str(), nullptr, nullptr);

        glfwMakeContextCurrent(m_window);
        
        if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            std::cout << "Couldn't initialize GLAD!" << std::endl;
        }

        glClearColor(0.2f, 0.4f, 0.6f, 1.0f);
    }

    void Window::on_update() {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
}