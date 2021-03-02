#include <Hgenx.h>




class Sandbox : public Hgenx::Application
{
public:
	Sandbox()
	{

	}

	virtual ~ Sandbox()
	{

	}
};

Hgenx::Application* Hgenx::CreateApplication()
{
	return new Sandbox();
}