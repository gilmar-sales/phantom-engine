#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/fmt.h>

namespace ph {
    class Log
    {
    public:
        static void init();
        
        inline static std::shared_ptr<spdlog::logger>& get_core_logger() { return s_core_logger; }
        inline static std::shared_ptr<spdlog::logger>& get_client_logger() { return s_client_logger; }

    private:
        static std::shared_ptr<spdlog::logger> s_core_logger;
        static std::shared_ptr<spdlog::logger> s_client_logger;
    };
    
}

#define PH_CORE_TRACE(...) ::ph::Log::get_core_logger()->trace(__VA_ARGS__)
#define PH_CORE_INFO(...) ::ph::Log::get_core_logger()->info(__VA_ARGS__)
#define PH_CORE_WARN(...) ::ph::Log::get_core_logger()->warn(__VA_ARGS__)
#define PH_CORE_ERROR(...) ::ph::Log::get_core_logger()->error(__VA_ARGS__)
#define PH_CORE_CRITICAL(...) ::ph::Log::get_core_logger()->critical(__VA_ARGS__)

#define PH_CLIENT_TRACE(...) ::ph::Log::get_client_logger()->trace(__VA_ARGS__)
#define PH_CLIENT_INFO(...) ::ph::Log::get_client_logger()->info(__VA_ARGS__)
#define PH_CLIENT_WARN(...) ::ph::Log::get_client_logger()->warn(__VA_ARGS__)
#define PH_CLIENT_ERROR(...) ::ph::Log::get_client_logger()->error(__VA_ARGS__)
#define PH_CLIENT_CRITICAL(...) ::ph::Log::get_client_logger()->critical(__VA_ARGS__)