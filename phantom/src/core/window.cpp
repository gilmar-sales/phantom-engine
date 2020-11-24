#include <phpch.h>

#include "window.h"

namespace ph {
    static unsigned s_window_count = 0;

    static void glfw_error_callback(int error, const char* description)
    {
        PH_CORE_ERROR("GLFW ERROR ({0}): {1}", error, description);
    }

    Window::Window(std::string title, unsigned width, unsigned height) {
        m_data = WindowData{ title, width, height };

        int success = glfwInit();

        startup();
    }

    Window::~Window()
    {
        shutdown();
    }

    void Window::on_update() {
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

    void Window::startup()
    {
        if (!s_window_count)
        {
            if (!glfwInit())
                PH_CORE_ERROR("Couldn't initialize GLFW!");
            else
                PH_CORE_INFO("Creating window {0} {1} {2}", m_data.title, m_data.width, m_data.height);

            glfwSetErrorCallback(glfw_error_callback);
        }
        
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

        s_window_count++;
        glfwWindowHint(GLFW_MAXIMIZED, 1);
        m_window = glfwCreateWindow(m_data.width, m_data.height, m_data.title.c_str(), nullptr, nullptr);

        glfwMakeContextCurrent(m_window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            PH_CORE_ERROR("Couldn't initialize GLAD!");
        }
        else
            PH_CORE_INFO("GLAD initialized!");

        PH_CORE_INFO("OpenGL {1}", glGetString(GL_VENDOR), glGetString(GL_VERSION));
        PH_CORE_INFO("{0} ", glGetString(GL_RENDERER));

        glClearColor(0.2f, 0.4f, 0.6f, 1.0f);

        glfwSetWindowUserPointer(m_window, &m_data);
        glfwSwapInterval(1);

        glClearColor(0.2f, 0.4f, 0.6f, 1.0f);

        //Set GLFW callbacks
        glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            data.width = width;
            data.height = height;

            WindowResizeEvent event(width, height);
            data.event_callback(event);
            });

        glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data.event_callback(event);
            });

        glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int modes) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            switch (action) {
            case GLFW_PRESS: {
                KeyPressedEvent event(key, 0);
                data.event_callback(event);
                break;
            }
            case GLFW_RELEASE: {
                KeyReleasedEvent event(key);
                data.event_callback(event);
                break;
            }
            case GLFW_REPEAT: {
                KeyPressedEvent event(key, 1);
                break;
            }
            }
            });

        glfwSetCharCallback(m_window, [](GLFWwindow* window, unsigned int key) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            KeyTypedEvent event(key);
            data.event_callback(event);
            });

        glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            switch (action) {
            case GLFW_PRESS: {
                MouseButtonPressedEvent event(button);
                data.event_callback(event);
                break;
            }
            case GLFW_RELEASE: {
                MouseButtonReleasedEvent event(button);
                data.event_callback(event);
                break;
            }
            }
            });

        glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            MouseScrolledEvent event((float)xOffset, (float)yOffset);
            data.event_callback(event);
            });

        glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double x, double y) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            MouseMoveEvent event((float)x, (float)y);
            data.event_callback(event);
            });
    }

    void Window::shutdown()
    {
        if (s_window_count > 1)
        {
            glfwDestroyWindow(m_window);
        }
        else glfwTerminate();
        s_window_count--;
    }

}
