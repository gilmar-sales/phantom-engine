#pragma once

#include "core.h"
#include "log.h"
#include "application.h"


extern ph::Application* ph::create_application();

#ifdef PH_PLATFORM_WINDOWS

int main(int argc, char** argv) {
    return 0;
}

#endif

#ifdef PH_PLATFORM_LINUX

int main(int argc, char** argv) {

    ph::Log::init();

    PH_CORE_INFO("Initializing logger!");
    PH_CLIENT_INFO("Initializing logger");

    auto app = ph::create_application();

    app->run();

    return 0;
}

#endif