
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
		  if Multithreading is used shared_ptr is not quite thread safe!!!
		*/
		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);

		glGenVertexArrays(1, &m_VertexArray);
		glBindVertexArray(m_VertexArray);

		glGenBuffers(1, &m_VertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);

		/* pass the vertices of a triangle in a counter-clockwise */
		float vertices[3 * 3] = {
			-0.5f, -0.5f, 0.0f,	// left corner
			 0.5f, -0.5f, 0.0f,	// right corner
			 0.0f,  0.5f, 0.0f	// top vertex
		};

		glBufferData(GL_ARRAY_BUFFER, sizeof vertices, vertices, GL_STATIC_DRAW);
		/* zero indicates the first object in the buffer*/
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), nullptr);  /* zero; is the same as above refers to the first object passed in buffer
																					   3; stands for 3 vertices; GL_FLOAT; type of data, GL_FALSE; normalize or not , 
																					   3*sizeof(float) ; the space in between each row 3 floats in each row
																					   nullptr ; the start of data(colum index) ; default value is zero; 
																					   if you have other info in the array such as texture , UV coordinates 
																					   then to use those you pass in the value for start of those column index
																					 */
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
			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
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


