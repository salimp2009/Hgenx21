
#include "hgpch.h"
#include "Hgenx/Application.h"

#include "Hgenx/Events/ApplicationEvent.h"
#include "Hgenx/Log.h"
#include "Hgenx/Events/KeyEvent.h"
#include "Hgenx/Events/MouseEvent.h"

#include <GLFW/glfw3.h>

/*TODO ; Delete these if lambda works*/
//m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
//m_Window->SetEventCallback([this](auto&&... x)->decltype(auto) {return Application::OnEvent(std::forward<decltype(x)>(x)...); });


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
		HG_CORE_INFO("{0}",e);
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

	

}


