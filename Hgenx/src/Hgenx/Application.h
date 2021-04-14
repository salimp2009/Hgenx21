#pragma once

#include "Core.h"

#include "Window.h"
#include "Hgenx/Events/Event.h"
#include "Hgenx/Events/ApplicationEvent.h"
#include "Hgenx/LayerStack.h"
#include "Hgenx/ImGui/ImGuiLayer.h"

namespace Hgenx 
{

	class HGENX_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		static Application& Get() { return *s_Instance; }
		Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;

	};

	// To be defined in CLIENT
	Application* CreateApplication();

	
} // end of namespace


