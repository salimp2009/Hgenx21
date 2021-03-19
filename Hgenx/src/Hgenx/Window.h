#pragma once

#include "hgpch.h"

#include "Hgenx/Core.h"
#include "Hgenx/Events/Event.h"

namespace Hgenx
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(std::string title="Hgenx Engine", 
			unsigned int width=1280, unsigned int height=1080): 
			Title{std::move(title)}, Width{width}, Height{height} { }
	};

	/* Interface class for a desktop based Window to be implemented
	   by each Platform(mobile has surfaces no Window) */
	class HGENX_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth()  const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window Attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const= 0;
		virtual void* GetActiveWindow() const = 0; // Will be implemented in later videos

		static Window* Create(const WindowProps& props = WindowProps());
		
		/*TODO: will be replaced by Scope=std::unique_ptr<T>()*/
		//static std::unique_ptr<Window> Create(const WindowProps& props = WindowProps());
	};
















} // end of namespace
