#pragma once

#include "Hgenx/Core.h"
#include "Hgenx/Events/Event.h"

namespace Hgenx
{

	class HGENX_API Layer
	{
	public:
		Layer(std::string name = "Layer"); 
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		const std::string& GetName() const& { return m_DebugName; }

	private:
		std::string m_DebugName;

	};





} // end of namespace


