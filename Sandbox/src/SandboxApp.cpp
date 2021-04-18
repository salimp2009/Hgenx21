#include <Hgenx.h>


class ExampleLayer : public Hgenx::Layer
{
public:
	ExampleLayer():Layer{"Example"}
	{
		
	}

	virtual void OnUpdate() override
	{
		/*TODO: Delete this; used only for test purposes*/
		if (Hgenx::Input::IsKeyPressed(HG_KEY_TAB))
		{
			HG_TRACE("Tab key is pressed!");
		}

	}

	
	virtual void OnEvent(Hgenx::Event& event) override
	{
		HG_TRACE("{0}", event);
		
		/*TODO: Delete this; used only for test purposes*/
		if (event.GetEventType() == Hgenx::EventType::KeyPressed)
		{
			Hgenx::KeyPressedEvent& e = (Hgenx::KeyPressedEvent&)event;
			
			HG_TRACE("{0}", static_cast<char>(e.GetKeyCode()));
		}
	}

	virtual ~ExampleLayer(){}
};


class Sandbox : public Hgenx::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	virtual ~ Sandbox()
	{

	}
};

Hgenx::Application* Hgenx::CreateApplication()
{
	return new Sandbox();
}