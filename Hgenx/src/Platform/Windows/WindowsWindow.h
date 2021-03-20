#pragma once

#include "Hgenx/Window.h"

#include <GLFW/glfw3.h>


namespace Hgenx
{
	
	class WindowsWindow: public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		virtual void OnUpdate() override;

		virtual unsigned int GetWidth()  const override { return m_Data.Width; }
		virtual unsigned int GetHeight() const override { return m_Data.Height; }

		// Window Attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback=callback; }
		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override;
		
		// Will be implemented in later videos
		virtual void* GetNativeWindow() const override { return m_Window; }

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		// Refactor to unique_ptr or shared_ptr; maynot be needed since Application.h wraps w/ unique_ptr
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width{0};
			unsigned int Height{0};
			bool VSync{false};
			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};


} // end of namespace

