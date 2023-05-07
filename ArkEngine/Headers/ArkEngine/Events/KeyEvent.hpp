#pragma once

#include "ArkEngine/Events/Event.hpp"

namespace ArkEngine::Event
{
	// -------------------------------
	// ---------- Key Event ----------
	// -------------------------------
	class ARK_ENGINE_API KeyEvent : public Event
	{
		// Attributes
	protected:
		int keyCode;

		// Methods
	public:
		const int GetKeyCode() const { return keyCode; };

	protected:
		KeyEvent(const EventData& p_eventData, const int p_keyCode);
	};

	// -------------------------------
	// ------ Key Pressed Event ------
	// -------------------------------
	class ARK_ENGINE_API KeyPressedEvent : public KeyEvent
	{
		// Attributes
	private:
		unsigned int repeatCount;

		// Methods
	public:
		KeyPressedEvent(const int p_keyCode, const unsigned int p_repeatCount);

		const std::string& ToString() const override;
		
		const int GetRepeatCount() const { return repeatCount; };
	};

	// -------------------------------
	// ------ Key Released Event -----
	// -------------------------------
	class ARK_ENGINE_API KeyReleasedEvent : public KeyEvent
	{
		// Attributes
	private:

		// Methods
	public:
		KeyReleasedEvent(const int p_keyCode);

		const std::string& ToString() const override;
	};
}
