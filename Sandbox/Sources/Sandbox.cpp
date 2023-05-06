#include <ArkEngine.hpp>

class SandBox : public ArkEngine::Application
{
};

ArkEngine::Application* ArkEngine::CreateApplication()
{
	return new SandBox;
}