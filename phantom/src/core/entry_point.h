#pragma once

#include "log.h"
#include "application.h"

extern ph::Application* ph::create_application();

int main(int argc, char** argv) {

    ph::Log::init();

    auto app = ph::create_application();

    app->run();

    return 0;
}