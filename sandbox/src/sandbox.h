#pragma once
#include "phantom.h"

class Sandbox : public ph::Application {
public:
    Sandbox() : ph::Application("sandbox", 1280, 720) {

    }

    ~Sandbox() = default;

    void on_update() override;
    void on_event() override;
};

ph::Application* ph::create_application() {
    return new Sandbox();
}