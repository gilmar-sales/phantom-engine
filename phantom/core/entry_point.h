#pragma once

#include "core.h"
#include "log.h"

#ifdef PH_PLATFORM_WINDOWS

int main(int argc, char** argv) {
    return 0;
}

#endif

#ifdef PH_PLATFORM_LINUX

int main(int argc, char** argv) {

    ph::Log::init();

    return 0;
}

#endif