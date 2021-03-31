#include <Hgenx.h>

class ExampleLayer : public Hgenx::Layer
{
public:
	ExampleLayer():Layer{"Example"}
	{
	}

	virtual void OnUpdate() override
	{
		HG_INFO("ExampleLayer::Update");
	}

	virtual void OnEvent(Hgenx::Event& event) override
	{
		HG_TRACE("{0}", event);
	}

	virtual ~ExampleLayer(){}
};


class Sandbox : public Hgenx::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Hgenx::ImGuiLayer());
	}

	virtual ~ Sandbox()
	{

	}
};

Hgenx::Application* Hgenx::CreateApplication()
{
	return new Sandbox();
}