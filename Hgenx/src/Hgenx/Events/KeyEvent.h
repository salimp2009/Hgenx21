#pragma once

#include "Event.h"

#include <sstream>

namespace Hgenx
{

	class HGENX_API KeyEvent : public Event
	{
	public:
		int GetKeyCode() const { return m_KeyCode; }
		virtual ~KeyEvent() {}

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode) :m_KeyCode{ keycode } {}

		int m_KeyCode;
	};

	class HGENX_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatcount) : KeyEvent{ keycode }, m_RepeatCount{ repeatcount } {}
		virtual ~KeyPressedEvent() {}

		int GetRepeatCount() const { return m_RepeatCount; }

		virtual std::string ToString() const override
		{
			// Original Code; Test!!!!
			//std::stringstream ss;
			//ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			//return ss.str();

			return { "KeyPressedEvent: " + std::to_string(m_KeyCode) + " ("  + std::to_string(m_RepeatCount) + " repeats)" };
		}

		EVENT_CLASS_TYPE(KeyPressed)
	
	private:
		int m_RepeatCount;
	
	};

	class HGENX_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode) : KeyEvent{ keycode } {}
		virtual ~KeyReleasedEvent() {}

		virtual std::string ToString() const override
		{
			//std::stringstream ss;
			//ss << "KeyReleasedEvent : " << m_KeyCode;
			//return ss.str();

			return {"KeyReleasedEvent : " + std::to_string(m_KeyCode)};
		}

		EVENT_CLASS_TYPE(KeyReleased)								// added ENUM_CLASS_TYPE to hint files by mistake; 
	};

	class HGENX_API KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int keycode) : KeyEvent{ keycode } {}
		virtual ~KeyTypedEvent() {}

		virtual std::string ToString() const override
		{
			//std::stringstream ss;
			//ss << "KeyTypedEvent : " << m_KeyCode;
			//return ss.str();

			return { "KeyTypedEvent : " + std::to_string(m_KeyCode) };
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};

} // end of Hgenx namespace
