#pragma once

#include "Core.h"

#include "Window.h"
#include "Events/Event.h"

namespace Hgenx 
{

	class HGENX_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

	};

	// To be defined in CLIENT
	Application* CreateApplication();

	
}


