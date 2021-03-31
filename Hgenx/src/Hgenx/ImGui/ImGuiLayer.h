#pragma once

#include "Hgenx/Layer.h"

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
		float m_Time = 0.0f;

	};


} // end of namespace
