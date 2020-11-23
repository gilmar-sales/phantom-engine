#include <phantom.h>

#include "editor_layer.h"

class EditorApp : public ph::Application
{
public:
    EditorApp() : ph::Application("Phantom Editor", 1280, 720)
    {
        push_layer(new ph::EditorLayer());
    };
    ~EditorApp() = default;

    void on_event(ph::Event &e) {};
    void on_update()
    {

    }
};

ph::Application *ph::create_application()
{
    return new EditorApp();
}