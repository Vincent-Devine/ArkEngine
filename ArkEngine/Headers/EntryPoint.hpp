#pragma once

#include "Ark/Application.hpp"

#ifdef ARK_PLATFORM_WINDOWS

extern ArkEngine::Application* ArkEngine::CreateApplication();

int main(int argc, char** argv)
{
	ArkEngine::Application* app = ArkEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif