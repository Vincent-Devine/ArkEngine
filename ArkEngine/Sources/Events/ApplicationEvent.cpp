#include "ArkEngine/Events/ApplicationEvent.hpp"

#include <sstream>

namespace ArkEngine::Event
{
	// -------------------------------
	// ----- Window Resize Event -----
	// -------------------------------
	WindowResizeEvent::WindowResizeEvent(const unsigned int p_width, const unsigned int p_height)
		: Event(EventData{ "WindowResize", EventType::WindowResize, EventCategory::Application })
		, width(p_width)
		, height(p_height)
	{
	}

	const std::string WindowResizeEvent::ToString() const
	{
		std::stringstream ss;
		ss << "WindowResizeEvent: " << width << ", " << height;
		return ss.str();
	}

	// -------------------------------
	// ------ Window Close Event -----
	// -------------------------------
	WindowCloseEvent::WindowCloseEvent()
		: Event(EventData{ "WindowClose", EventType::WindowClose, EventCategory::Application })
	{
	}

	// -------------------------------
	// -------- App Tick Event -------
	// -------------------------------
	AppTickEvent::AppTickEvent()
		: Event(EventData{ "AppTick", EventType::AppTick, EventCategory::Application })
	{
	}

	// -------------------------------
	// ------- App Update Event ------
	// -------------------------------
	AppUpdateEvent::AppUpdateEvent()
		: Event(EventData{ "AppUpdate", EventType::AppUpdate, EventCategory::Application })
	{
	}

	// -------------------------------
	// ------- App Render Event ------
	// -------------------------------
	AppRenderEvent::AppRenderEvent()
		: Event(EventData{ "AppRender", EventType::AppRender, EventCategory::Application })
	{
	}
}