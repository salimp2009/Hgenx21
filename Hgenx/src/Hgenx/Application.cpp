
#include "hgpch.h"
#include "Hgenx/Application.h"

#include "Hgenx/Log.h"
#include "Hgenx/Events/KeyEvent.h"
#include "Hgenx/Events/MouseEvent.h"

#include <glad/glad.h>

#include "Input.h"



namespace Hgenx 
{
	
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		HG_CORE_ASSERT(!s_Instance, "Application alreay exists!");
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(HG_BIND_EVENT_FN(Application::OnEvent));
		
		/*TODO ; test with unique_ptr but use std::move(); dont use .get() because it gets deleted in LayerStack and creates ownership/lifetimes
		  alternative is to use shared_ptr or add PopOverlay into Application destructor; and after it is poped then delete the raw pointer
		  if Multithreading is used shared_ptr is not thread safe!!!
		*/
		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);

		unsigned int id;
		glGenVertexArrays(1, &id);
	}

	Application::~Application()
	{
		
	}


	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatch(e);
		dispatch.Dispatch<WindowCloseEvent>(HG_BIND_EVENT_FN(Application::OnWindowClose));
		
		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
		{
			if (e.Handled)
			{
				break;
			}
			(*it)->OnEvent(e);
		}

	}

	void Application::Run()
	{
		
		while (m_Running)
		{
			glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			
			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}

			m_ImGuiLayer->Begin();

			for (Layer* layer : m_LayerStack)
			{
				layer->OnImGuiRender();
			}

			m_ImGuiLayer->End();

			m_Window->OnUpdate();
		}
	}


	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}


