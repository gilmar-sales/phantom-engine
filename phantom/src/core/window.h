#pragma once

#include <string>
#include <string_view>
#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <events/application_event.h>
#include <events/key_event.h>
#include <events/mouse_event.h>

#include <renderer/render_context.h>

namespace ph {

    class Window {
    public:
        using EventCallbackFn = std::function<void(Event&)>;

        struct WindowData
        {
            std::string title;
            unsigned width;
            unsigned height;
            EventCallbackFn event_callback;
        };

        Window(std::string title, unsigned width, unsigned height);
        ~Window();

        void on_update();

        void set_event_callback(const EventCallbackFn& callback) { m_data.event_callback = callback; }

        inline std::string_view get_title() { return m_data.title; }
        inline unsigned get_width() { return m_data.width; }
        inline unsigned get_height() { return m_data.height; }

        GLFWwindow* get_native_window() { return m_window; }
    private:

        void startup();
        void shutdown();

        GLFWwindow* m_window;
        std::unique_ptr<RenderContext> m_context;
        WindowData m_data;
    };
}