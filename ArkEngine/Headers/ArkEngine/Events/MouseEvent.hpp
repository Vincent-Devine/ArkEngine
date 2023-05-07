#pragma once

#include "ArkEngine/Events/Event.hpp"
#include "ArkEngine/Core/MouseCode.hpp"

namespace ArkEngine::Event
{
	// -------------------------------
	// ------ Mouse Moved Event ------
	// -------------------------------
	class ARK_ENGINE_API MouseMovedEvent : public Event
	{
		// Attributes
	private:
		float mouseX, mouseY;

		// Methods
	public:
		MouseMovedEvent(const float& p_x, const float& p_y);

		const std::string ToString() const override;

		const float& GetXMouse() const { return mouseX; };
		const float& GetYMouse() const { return mouseY; };
	};

	// -------------------------------
	// ---- Mouse Scrolled Event -----
	// -------------------------------
	class ARK_ENGINE_API MouseScrolledEvent : public Event
	{
		// Attributes
	private:
		float XOffset, YOffset;

		// Methods
	public:
		MouseScrolledEvent(const float& p_x, const float& p_y);

		const std::string ToString() const override;

		const float& GetXOffset() const { return XOffset; };
		const float& GetYOffset() const { return YOffset; };
	};

	// -------------------------------
	// ----- Mouse Button Event ------
	// -------------------------------
	class ARK_ENGINE_API MouseButtonEvent : public Event
	{
		// Attributes
	protected:
		Core::MouseCode mouseCode;

		// Methods
	public:
		MouseButtonEvent(const EventData& p_eventData, const Core::MouseCode p_mouseCode);
	};

	// -------------------------------
	// - Mouse Button Pressed Event --
	// -------------------------------
	class ARK_ENGINE_API MouseButtonPressedEvent : public MouseButtonEvent
	{
		// Methods
	public:
		MouseButtonPressedEvent(const Core::MouseCode p_mouseCode);

		const std::string ToString() const override;
	};

	// -------------------------------
	// - Mouse Button Released Event -
	// -------------------------------
	class ARK_ENGINE_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
		// Methods
	public:
		MouseButtonReleasedEvent(const Core::MouseCode p_mouseCode);

		const std::string ToString() const override;
	};
}