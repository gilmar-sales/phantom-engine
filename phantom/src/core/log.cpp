#include "log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace ph {
    std::shared_ptr<spdlog::logger> Log::s_core_logger;
    std::shared_ptr<spdlog::logger> Log::s_client_logger;

    void Log::init() {
        spdlog::set_pattern("%^[%c] [%n] [%l]%$ %v");
		s_core_logger = spdlog::stdout_color_mt("phantom");
		s_core_logger->set_level(spdlog::level::trace);

		s_client_logger = spdlog::stdout_color_mt("app");
		s_client_logger->set_level(spdlog::level::trace);
    }
}