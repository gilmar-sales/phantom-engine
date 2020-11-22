#pragma once

#include "platform.h"

#ifdef PH_DEBUG
	#if defined(PH_PLATFORM_WINDOWS)
		#define debug_break() __debugbreak()
	#elif defined(PH_PLATFORM_LINUX)
		#include <signal.h>
	#define debug_break() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define PH_ASSERT
#else
#define debug_break()
#endif
