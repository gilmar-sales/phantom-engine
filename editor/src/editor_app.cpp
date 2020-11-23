#pragma once

#include <phantom.h>

class EditorApp : public ph::Application {
public:
    EditorApp() : ph::Application("Phantom Editor", 1280, 720)
    {
    
    }

    ~EditorApp() = default;

    void on_update() override
    {
    }
};

ph::Application* ph::create_application()
{
    return new EditorApp();
}