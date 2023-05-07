#include "ArkEngine/Events/KeyEvent.hpp"

#include <sstream>

namespace ArkEngine::Event
{
	// -------------------------------
	// ---------- Key Event ----------
	// -------------------------------
	KeyEvent::KeyEvent(const EventData& p_eventData, const int p_keyCode)
		: Event(p_eventData)
		, keyCode(p_keyCode)
	{
	}

	// -------------------------------
	// ------ Key Pressed Event ------
	// -------------------------------
	KeyPressedEvent::KeyPressedEvent(const int p_keyCode, const unsigned int p_repeatCount)
		: KeyEvent( EventData{"KeyPressed", EventType::KeyPressed, EventCategory::KeyBoard }, p_keyCode)
		, repeatCount(p_repeatCount)
	{
	}

	const std::string KeyPressedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "KeyPressedEvent: " << keyCode << " (" << repeatCount << " repeats)";
		return ss.str();
	}

	// -------------------------------
	// ------ Key Released Event -----
	// -------------------------------
	KeyReleasedEvent::KeyReleasedEvent(const int p_keyCode)
		: KeyEvent(EventData{ "KeyRelease", EventType::KeyReleased, EventCategory::KeyBoard }, p_keyCode)
	{
	}

	const std::string KeyReleasedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "KeyReleasedEvent: " << keyCode;
		return ss.str();
	}
}