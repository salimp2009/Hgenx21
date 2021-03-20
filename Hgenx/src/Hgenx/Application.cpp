
#include "hgpch.h"
#include "Hgenx/Application.h"

#include "Hgenx/Events/ApplicationEvent.h"
#include "Hgenx/Log.h"
#include "Hgenx/Events/KeyEvent.h"
#include "Hgenx/Events/MouseEvent.h"

#include <GLFW/glfw3.h>

namespace Hgenx 
{

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

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


