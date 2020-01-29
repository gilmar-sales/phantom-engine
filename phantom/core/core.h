#pragma once

#ifdef _WIN32
    #ifdef _WIN64
        #define PH_PLATFORM_WINDOWS
    #else
        #error windows 32-bits not supported!
    #endif
#elif defined(__linux__)
    #define PH_PLATFORM_LINUX
#endif
