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
		virtual void OnImGuiRender() override; /* TODO: will be implemented later*/

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;

	};


} // end of namespace
