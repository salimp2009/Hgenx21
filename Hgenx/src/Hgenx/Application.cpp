
#include "hgpch.h"
#include "Hgenx/Application.h"

#include "Hgenx/Events/ApplicationEvent.h"
#include "Hgenx/Log.h"
#include "Hgenx/Events/KeyEvent.h"
#include "Hgenx/Events/MouseEvent.h"

namespace Hgenx 
{

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			HG_TRACE(e);
		}

		if (e.IsInCategory(EventCategoryInput))
		{
			HG_TRACE(e);
		}
		
		KeyPressedEvent e2(32, 20);
		MouseMovedEvent e3(20.45f, 30.256f);
		
		//HG_INFO(e2);
		//HG_INFO(e3);
		//HG_TRACE(e3);
		//HG_INFO(e3);
		//HG_WARN(e3);
		//HG_FATAL(e3);
		while (true);
	}

}


