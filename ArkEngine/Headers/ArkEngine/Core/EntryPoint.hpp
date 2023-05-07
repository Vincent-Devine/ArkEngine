#pragma once

#include "ArkEngine/Core/Application.hpp"
#include "ArkEngine/Core/Logging.hpp"

#ifdef ARK_PLATFORM_WINDOWS

extern ArkEngine::Core::Application* ArkEngine::Core::CreateApplication();

int main(int argc, char** argv)
{
	ArkEngine::Core::Logging::OpenFile("log.txt");

	ArkEngine::Core::Application* app = ArkEngine::Core::CreateApplication();
	app->Run();
	delete app;

	ArkEngine::Core::Logging::CloseFile();
}

#endif