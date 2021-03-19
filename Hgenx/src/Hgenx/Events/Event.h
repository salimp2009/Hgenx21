#pragma once
#include "hgpch.h"

#include "Hgenx/Core.h"

//#include <string>
//#include <functional>

namespace Hgenx
{
	// Events are currently blocking type;when an event occurs it is dipatched immediately & holding other processes
	// To be implemented; to buffer event and add to a queue / event bus 
	// and process them during the "event part" of the update stage

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};



#define EVENT_CLASS_TYPE(type) static  EventType GetStaticType() {return EventType::type;}\
                               virtual EventType GetEventType() const override {return GetStaticType();}\
                               virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category;}

	// revised in the  current version; Using library no decllexport / import
	// will be refactored
	class HGENX_API Event
	{
		//friend class EventDispatcher;		// not used in the current version; not neccessary m_Handled is changed to public
	public:
		bool Handled{ false };				// revised to public from private(older version; on the youtube videos)

		virtual EventType GetEventType()			const = 0;
		virtual const char* GetName()				const = 0;
		virtual int GetCategoryFlags()				const = 0;
		virtual std::string ToString() const { return GetName(); } // REFACTORED ; not using ssstream; using to_string instead
		
		virtual ~Event() {};

		inline bool IsInCategory(EventCategory category) // the warning is to use enum class instead enum;
		{
			return GetCategoryFlags() & category;
		}


		//protected:
		//	bool Handled{ false };
	};

	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event) : m_Event{ event } {}

		template<typename T, typename F>
		constexpr bool  Dispatch(const F& func)   //  Added constexpr
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled |= func(static_cast<T&>(m_Event));  // changed from "m_Event.Handled =" to "m_Event.Handled |="
				return true;
			}
			return false; 
		}

	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& ost, const Event& e)
	{
		return ost << e.ToString();
	}
}
