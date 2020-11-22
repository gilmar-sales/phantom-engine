#include <phpch.h>

#include "window.h"

namespace ph {
    Window::Window(const WindowData& data) {
        m_data = data;

        int success = glfwInit();

        if(!success) {
            PH_CORE_ERROR("Couldn't initialize GLFW!");
        }

        m_window = glfwCreateWindow(data.width, data.height, data.title.c_str(), nullptr, nullptr);

        glfwMakeContextCurrent(m_window);
        
        if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            PH_CORE_ERROR("Couldn't initialize GLAD!");
        }

        PH_CORE_INFO("OpenGL {1}", glGetString(GL_VENDOR), glGetString(GL_VERSION));
        PH_CORE_INFO("{0} ", glGetString(GL_RENDERER));

        glClearColor(0.2f, 0.4f, 0.6f, 1.0f);
    }

    Window::~Window()
    {
        glfwTerminate();
    }

    void Window::on_update() {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
}