#pragma once

#include "Event.h"

namespace Hgenx
{
	class HGENX_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y) :m_MouseX{ x }, m_MouseY{ y } {}

		float GetX() const { return m_MouseX; }
		float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();

			//to_string from float might not be good for floats
			//return { "MouseMovedEvent: "  + std::to_string(m_MouseX)+ ", "+ std::to_string(m_MouseY) };
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_MouseX, m_MouseY;
	};

	class HGENX_API MouseScrolledEvent :public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset) : m_XOffset{ xOffset }, m_YOffset{ yOffset } {}

		float GetXOffset() const { return m_XOffset; }
		float GetYOffset() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		
			//to_string from float might not be good for floats
			//return { "MouseScrolledEvent: " + std::to_string(GetXOffset()) + ", " + std::to_string(GetYOffset()) };
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_XOffset, m_YOffset;
	};

	class HGENX_API MouseButtonEvent :public Event
	{
	public:
		int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button) :m_Button{ button } {}

		int m_Button;
	};

	class HGENX_API MouseButtonPressedEvent :public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent{ button } {}

		std::string ToString() const override
		{
			//std::stringstream ss;
			//ss << "MouseButtonPressedEvent: " << m_Button;
			//return ss.str();

			return {  "MouseButtonPressedEvent: "  + std::to_string(m_Button)};
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class HGENX_API MouseButtonReleasedEvent:public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent{ button } {}

		std::string ToString() const override
		{
			//std::stringstream ss;
			//ss << "MouseButtonReleasedEvent: " << m_Button;
			//return ss.str();

			return { "MouseButtonReleasedEvent: " + std::to_string(m_Button) };
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};


} // end of name space