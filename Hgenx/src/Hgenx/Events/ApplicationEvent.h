#pragma once

#include "Event.h"

namespace Hgenx
{
	class HGENX_API WindowResizeEvent :public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned height) : m_Width{ width }, m_Height{ height } {}

		unsigned int GetWidth()  const { return m_Width; }
		unsigned int GetHeight() const { return m_Height; }

		virtual ~WindowResizeEvent(){}

		virtual std::string ToString() const override
		{
			//std::stringstream ss;
			//ss << " WindowResizeEvent: " << m_Width << ", " << m_Height;
			//return ss.str();

			// TODO: Refactored ; Works but check performance; for floats used fmt::format() in other events 
			return { ("WindowsResizeEvent: ") + std::to_string(m_Width) + ", " + std::to_string(m_Width) };
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int m_Width, m_Height;
	};

	class HGENX_API WindowCloseEvent :public Event
	{
	public:
		WindowCloseEvent() = default;

		virtual ~WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class HGENX_API AppTickEvent :public Event
	{
	public:
		AppTickEvent() = default;

		virtual ~AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class HGENX_API AppUpdateEvent :public Event
	{
	public:
		AppUpdateEvent() = default;
		virtual ~AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class HGENX_API AppRenderEvent :public Event
	{
	public:
		AppRenderEvent() = default;
		virtual ~AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};















} // end of Hgenx namespace