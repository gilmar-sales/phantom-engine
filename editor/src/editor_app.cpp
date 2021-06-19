#include <phantom.h>

#include "editor_layer.h"
#include "panels/hierarchy_panel.h"

class EditorApp : public ph::Application
{
public:
    EditorApp() : ph::Application("Phantom Editor", 1280, 720)
    {
        push_layer(new ph::EditorLayer(m_scene));
    };
    ~EditorApp() = default;

    void on_event(ph::Event &e) {};
    void on_update()
    {

    }
private:
};

ph::Application *ph::create_application()
{
    return new EditorApp();
}