#include "hgpch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace Hgenx 
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		/** %^ start color , [%T] time stamp, %n: logger name (e.g.:Client or Core) , %v actual message, %$ end color */
		spdlog::set_pattern("%^[%T] %n: %v%$");
		
		

		//ORIGINAL METHODs
		//s_CoreLogger = spdlog::stdout_color_mt("HGENX");
		//s_ClientLogger = spdlog::stdout_color_mt("APP");
		
		// Alternative to avoid unneccessary copying; TESTED; it works;
		s_CoreLogger = std::move(spdlog::stdout_color_mt("HGENX"));
		s_CoreLogger->set_level(spdlog::level::trace);
		
		s_ClientLogger = std::move(spdlog::stdout_color_mt("APP"));
		s_ClientLogger->set_level(spdlog::level::trace);

	}

}


