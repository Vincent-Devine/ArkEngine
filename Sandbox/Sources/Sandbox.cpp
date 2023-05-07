#include <ArkEngine.hpp>

class SandBox : public ArkEngine::Core::Application
{
};

ArkEngine::Core::Application* ArkEngine::Core::CreateApplication()
{
	return new SandBox;
}