#include "ArkEngine/Events/MouseEvent.hpp"
#include <sstream>

namespace ArkEngine::Event
{
	// -------------------------------
	// ------ Mouse Moved Event ------
	// -------------------------------
	MouseMovedEvent::MouseMovedEvent(const float& p_x, const float& p_y)
		: Event(EventData{ "MouseMoved", EventType::MouseMoved, EventCategory::Mouse })
		, mouseX(p_x)
		, mouseY(p_y)
	{
	}

	const std::string MouseMovedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "MouseMovedEvent: " << mouseX << ", " << mouseY;
		return ss.str();
	}

	// -------------------------------
	// ---- Mouse Scrolled Event -----
	// -------------------------------
	MouseScrolledEvent::MouseScrolledEvent(const float& p_x, const float& p_y)
		: Event(EventData{ "MouseScrolled", EventType::MouseScrolled, EventCategory::MouseButton })
		, XOffset(p_x)
		, YOffset(p_y)
	{
	}

	const std::string MouseScrolledEvent::ToString() const
	{
		std::stringstream ss;
		ss << "MouseScrolledEvent: " << XOffset << ", " << YOffset;
		return ss.str();
	}

	// -------------------------------
	// ----- Mouse Button Event ------
	// -------------------------------
	MouseButtonEvent::MouseButtonEvent(const EventData& p_eventData, const Core::MouseCode p_mouseCode)
		: Event(p_eventData)
		, mouseCode(p_mouseCode)
	{
	}

	// -------------------------------
	// - Mouse Button Pressed Event --
	// -------------------------------
	MouseButtonPressedEvent::MouseButtonPressedEvent(const Core::MouseCode p_mouseCode)
		: MouseButtonEvent(EventData{ "MouseButtonPressed", EventType::MouseButtonPressed, EventCategory::MouseButton }, p_mouseCode)
	{
	}

	const std::string MouseButtonPressedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "MouseButtonPressedEvent: " << mouseCode;
		return ss.str();
	}

	// -------------------------------
	// - Mouse Button Released Event -
	// -------------------------------
	MouseButtonReleasedEvent::MouseButtonReleasedEvent(const Core::MouseCode p_mouseCode)
		: MouseButtonEvent(EventData{ "MouseButtonReleased", EventType::MouseButtonReleased, EventCategory::MouseButton }, p_mouseCode)
	{
	}

	const std::string MouseButtonReleasedEvent::ToString() const
	{
		std::stringstream ss;
		ss << "MouseButtonReleasedEvent: " << mouseCode;
		return ss.str();
	}
}