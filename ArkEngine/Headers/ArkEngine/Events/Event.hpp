#pragma once

#include "ArkEngine/Core/Core.hpp"

#include <string>
#include <functional>

namespace ArkEngine::Event
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMouved, MouseScrolled
	};

	enum EventCategory : int
	{
		None = 0,
		Application = 1,
		Input		= 2,
		KeyBoard	= 3,
		Mouse		= 4,
		MouseButton = 5
	};

	struct EventData
	{
		const char* name;
		const EventType eventType;
		EventCategory eventCategory;
	};

	class ARK_ENGINE_API Event
	{
		// Attributes
	protected:
		const char* name;
		EventType eventType;
		EventCategory eventCategory;
		bool handled;

		// Methods
	public:
		Event(const EventData& p_eventData);

		bool IsInCategory(const EventCategory& p_category);
		virtual const std::string& ToString() const { return GetName(); };

		const char* GetName() const				{ return name; };
		const EventType& GetEventType() const	{ return eventType; };
		const int GetCategory() const			{ return eventCategory; };
	};
} // namespace