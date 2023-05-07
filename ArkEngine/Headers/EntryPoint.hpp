#pragma once

#include "Ark/Application.hpp"
#include "Logging.hpp"

#ifdef ARK_PLATFORM_WINDOWS

extern ArkEngine::Application* ArkEngine::CreateApplication();

int main(int argc, char** argv)
{
	Logging::OpenFile("log.txt");

	LOG("This is a Info", LOG_LEVEL::Info);
	LOG("This is a Validation", LOG_LEVEL::Validation);
	LOG("This is a Warning", LOG_LEVEL::Warning);
	LOG("This is a Critical", LOG_LEVEL::Critical);
	Assertion(1 == 1, "Message who don't be show");
	Assertion(1 != 1, "Assertion message need to be show");

	ArkEngine::Application* app = ArkEngine::CreateApplication();
	app->Run();
	delete app;

	Logging::CloseFile();
}

#endif