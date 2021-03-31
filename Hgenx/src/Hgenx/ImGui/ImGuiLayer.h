#pragma once

#include "Hgenx/Layer.h"

#include "Hgenx/Events/MouseEvent.h"
#include "Hgenx/Events/ApplicationEvent.h"
#include "Hgenx/Events/KeyEvent.h"


namespace Hgenx
{
	class HGENX_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		virtual ~ImGuiLayer() = default;
	
		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnImGuiRender() override; /* TODO: will be implemented later*/
		virtual void OnEvent(Event& event)override;
	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyPressedEvent& e);
		
		bool OnWindowResizedEvent(WindowResizeEvent& e);


	private:
		float m_Time = 0.0f;

	};


} // end of namespace
