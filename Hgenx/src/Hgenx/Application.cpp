
#include "hgpch.h"
#include "Hgenx/Application.h"

#include "Hgenx/Log.h"
#include "Hgenx/Events/KeyEvent.h"
#include "Hgenx/Events/MouseEvent.h"

#include <GLFW/glfw3.h>


namespace Hgenx 
{

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(HG_BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{

	}

	void Application::OnEvent(Event& e)
	{
		/* Original WindowClose event call*/
		EventDispatcher dispatch(e);
		dispatch.Dispatch<WindowCloseEvent>(HG_BIND_EVENT_FN(Application::OnWindowClose));
		
		HG_CORE_TRACE("{0}",e);
	}


	void Application::Run()
	{
		
	
		while (m_Running)
		{
			glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}


