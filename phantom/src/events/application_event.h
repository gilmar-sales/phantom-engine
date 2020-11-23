#pragma once

#include "event.h"

namespace ph
{
	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned width, unsigned height)
			: m_width(width), m_height(height) {}

		inline unsigned get_width() const { return m_width; }
		inline unsigned get_height() const { return m_height; }

		std::string to_string() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << get_width() << ", " << get_height();
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
			//static EventType GetStaticType() { return EventType::WindowResize; }
			//virtual EventType GetEventType() const override { return GetStaticType(); }
			//virtual const char *GetName() const override { return "WindowResize"; }

			//virtual int GetCategoryFlags() const override { return EventCategoryApplication; }

	private:
		unsigned m_width, m_height;
	};

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
			/* static EventType GetStaticType() { return EventType::WindowClose; }
			virtual EventType GetEventType() const override { return GetStaticType(); }
			virtual const char *GetName() const override { return "WindowClose"; }

			virtual int GetCategoryFlags() const override { return EventCategoryApplication; } */
	};

	class AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
			/* static EventType GetStaticType() { return EventType::AppTick; }
			virtual EventType GetEventType() const override { return GetStaticType(); }
			virtual const char *GetName() const override { return "AppTick"; }

			virtual int GetCategoryFlags() const override { return EventCategoryApplication; } */
	};

	class AppUpdateEvent : public Event
	{
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
			/* static EventType GetStaticType() { return EventType::AppUpdate; }
			virtual EventType GetEventType() const override { return GetStaticType(); }
			virtual const char *GetName() const override { return "AppUpdate"; }

			virtual int GetCategoryFlags() const override { return EventCategoryApplication; } */
	};
} // namespace ph