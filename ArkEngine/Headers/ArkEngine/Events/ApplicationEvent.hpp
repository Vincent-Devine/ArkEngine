#pragma once

#include "ArkEngine/Events/Event.hpp"

namespace ArkEngine::Event
{
	// -------------------------------
	// ----- Window Resize Event -----
	// -------------------------------
	class ARK_ENGINE_API WindowResizeEvent : public Event
	{
		// Attributes
	private:
		unsigned int width, height;

		// Methods
	public:
		WindowResizeEvent(const unsigned int p_width, const unsigned int p_height);
		
		const std::string ToString() const override;

		const unsigned int GetWidth() const { return width; };
		const unsigned int GetHeight() const { return height; };
	};

	// -------------------------------
	// ------ Window Close Event -----
	// -------------------------------
	class ARK_ENGINE_API WindowCloseEvent : public Event
	{
		// Methods
	public:
		WindowCloseEvent();
	};

	// -------------------------------
	// -------- App Tick Event -------
	// -------------------------------
	class ARK_ENGINE_API AppTickEvent : public Event
	{
		// Methods
	public:
		AppTickEvent();
	};

	// -------------------------------
	// ------- App Update Event ------
	// -------------------------------
	class ARK_ENGINE_API AppUpdateEvent : public Event
	{
		// Methods
	public:
		AppUpdateEvent();
	};

	// -------------------------------
	// ------- App Render Event ------
	// -------------------------------
	class ARK_ENGINE_API AppRenderEvent : public Event
	{
		// Methods
	public:
		AppRenderEvent();
	};
}