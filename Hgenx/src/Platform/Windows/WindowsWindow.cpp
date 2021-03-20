#include "hgpch.h"
#include "WindowsWindow.h"



namespace Hgenx
{
	static bool s_GLFWIinitialized = false;

	static void GLFWErrorCallback(int error, const char* description)
	{
		HG_CORE_ERROR("GLFW Error ({0}):{1}", error, description);
	}

	Window* Window::Create(const WindowProps& props)
	{

		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}


	void WindowsWindow::Init(const WindowProps& props)
	{

		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		HG_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWIinitialized)
		{
			int success = glfwInit();
			HG_CORE_ASSERT(success, "Could not Initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWIinitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data); // m_Data has callbackfunction member which will be used to create callback in GLFW
		SetVSync(true);

	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
		{
			glfwSwapInterval(1); // waits for 1 frame ; 
		}
		else
		{
			glfwSwapInterval(0);
		}
		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}


} // end of namespace
