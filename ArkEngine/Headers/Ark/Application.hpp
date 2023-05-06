#pragma once

#include "Core.hpp"

namespace ArkEngine
{
	class ARK_API Application
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
