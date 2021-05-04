#pragma once

#ifdef HG_PLATFORM_WINDOWS
#if HG_DYNAMIC_LINK
	#ifdef HG_BUILD_DLL
		#define HGENX_API __declspec(dllexport)
	#else
		#define HGENX_API __declspec(dllimport)
	#endif 
#else
	#define HGENX_API
#endif
#else
	#error HGenX only support Windows
#endif 


#ifdef HG_DEBUG
	#if defined(HG_PLATFORM_WINDOWS)
		#define HG_DEBUGBREAK() __debugbreak()
	#elif defined(HG_PLATFORM_LINUX)
		#include <signal.h>
		#define HG_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesnot support debugbreak yet!"
	#endif
	#define HG_ENABLE_ASSERTS
#else	
	#define HG_DEBUGBREAK()
#endif



#ifdef HG_ENABLE_ASSERTS
	#define HG_ASSERT(x, ...) { if(!(x)) { HG_ERROR("Assertion Failed: {0}", __VA_ARGS__);  HG_DEBUGBREAK();} }
	#define HG_CORE_ASSERT(x, ...) { if(!(x)) { HG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);  HG_DEBUGBREAK(); }}
#else
	#define HG_ASSERT(x, ...)
	#define HG_CORE_ASSERT(x, ...)
#endif


#define HG_BIND_EVENT_FN(fn) [this](auto&&... x)->decltype(auto) {return fn(std::forward<decltype(x)>(x)...); }
/* TODO: Alternative to test with a variadic overloader to replace std::function in Windows.h*/
#define HG_BIND_EVENT_FN_ALT(fn) [this](auto&&... x)->decltype(auto)\
{\
	auto f= [](auto&& fnew, auto&&... x1)->decltype(auto){fnew(std::forward<decltype(x1)>(x1)...);};\
	return f(fn,x...);\
}\


#define BIT(x) (1 << x)

