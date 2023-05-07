#pragma once

#include "Ark/Application.hpp"
#include "Logging.hpp"

#ifdef ARK_PLATFORM_WINDOWS

extern ArkEngine::Application* ArkEngine::CreateApplication();

int main(int argc, char** argv)
{
	Logging::OpenFile("log.txt");

	ArkEngine::Application* app = ArkEngine::CreateApplication();
	app->Run();
	delete app;

	Logging::CloseFile();
}

#endif