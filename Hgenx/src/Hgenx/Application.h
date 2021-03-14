#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Hgenx 
{

	class HGENX_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();


}


