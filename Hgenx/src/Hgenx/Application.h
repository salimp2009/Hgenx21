#pragma once

#include "Core.h"

#include "Window.h"
#include "Hgenx/Events/Event.h"
#include "Hgenx/Events/ApplicationEvent.h"
#include "Hgenx/LayerStack.h"

#include "Hgenx/ImGui/ImGuiLayer.h"
#include "Hgenx/Renderer/Shader.h"

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

		/*TODO; this is temporary; Will be replaced by custom classes and shared_ptr*/
		unsigned int m_VertexArray{ 0 };
		unsigned int m_VertexBuffer{ 0 };
		unsigned int m_IndexBuffer{ 0 };
		std::unique_ptr<Shader> m_Shader;
	private:
		static Application* s_Instance;

	};

	// To be defined in CLIENT
	Application* CreateApplication();

	
} // end of namespace


