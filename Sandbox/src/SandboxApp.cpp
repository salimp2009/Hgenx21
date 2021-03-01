#include <Hgenx.h>



class Sandbox : public Hgenx::Application
{
public:
	Sandbox()
	{

	}

	~ Sandbox()
	{

	}
};

Hgenx::Application* Hgenx::CreateApplication()
{
	return new Sandbox();
}