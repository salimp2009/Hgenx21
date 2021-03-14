#pragma once

#ifdef HG_PLATFORM_WINDOWS
	#ifdef HG_BUILD_DLL
		#define HGENX_API __declspec(dllexport)
	#else
		#define HGENX_API __declspec(dllimport)
	#endif
#else
	#error Hazel only support Windows	
#endif 


#define BIT(x) (1 << x)

