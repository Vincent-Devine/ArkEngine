#pragma once

#include "Core.hpp"

namespace ArkEngine::Core
{
	class ARK_ENGINE_API Application
	{
		// Methods
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be define in client
	Application* CreateApplication();
}