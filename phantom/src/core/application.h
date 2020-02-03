#pragma once

#include "window.h"

namespace ph {
    class Application {
    public:
        Application();
        virtual ~Application();

    private:
        Window* m_window;
    };
}