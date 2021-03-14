#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace Hgenx 
{

	class HGENX_API Log
	{

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

} 
// Lambda version; Test; this works; try to do eliminate __VA_ARGS__
#define HG_CORE_TRACE_LAMBDA(...) []()->decltype(auto){::Hgenx::Log::GetCoreLogger()->trace(__VA_ARGS__);}()


// Core log macros
#define HG_CORE_TRACE(...)    ::Hgenx::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HG_CORE_INFO(...)     ::Hgenx::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HG_CORE_WARN(...)     ::Hgenx::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HG_CORE_ERROR(...)    ::Hgenx::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HG_CORE_FATAL(...)	  ::Hgenx::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define HG_TRACE(...)    ::Hgenx::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HG_INFO(...)     ::Hgenx::Log::GetClientLogger()->info(__VA_ARGS__)
#define HG_WARN(...)     ::Hgenx::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HG_ERROR(...)    ::Hgenx::Log::GetClientLogger()->error(__VA_ARGS__)
#define HG_FATAL(...)    ::Hgenx::Log::GetClientLogger()->critical(__VA_ARGS__)



