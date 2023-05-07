#pragma once

#ifdef ARK_PLATFORM_WINDOWS
	#ifdef ARK_BUILD_DLL
		#define ARK_ENGINE_API __declspec(dllexport)
	#else
		#define ARK_ENGINE_API __declspec(dllimport)
	#endif
#else
	#error ArkEngine only support Windows!
#endif