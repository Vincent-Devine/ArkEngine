#include "ArkEngine/Events/Event.hpp"

namespace ArkEngine::Event
{
	Event::Event(const EventData& p_eventData)
		: name(p_eventData.name)
		, eventType(p_eventData.eventType)
		, eventCategory(p_eventData.eventCategory)
		, handled(false)
	{
	}

	bool Event::IsInCategory(const EventCategory& p_category)
	{
		return GetCategory() & p_category;
	}

	EventDispatcher::EventDispatcher(Event& p_event)
		: event(p_event)
	{
	}
}