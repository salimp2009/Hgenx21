#include <Hgenx.h>

#include <imgui/imgui.h>


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

	virtual void OnImGuiRender() override
	{
		// HomeWork Question : How to get rid of the linking error if below is included; compiles ok but cannot link
		// Solution FOR DDL; Add IMGUI_API=__declspec(dllexport); in Hazel Preprocessor definition also in ImGui 
		// Also add to SandBox to import IMGUI_API=__declspec(dllimport); Doing this enables Hazel to get 
		// this loaded from ImGui since Hazel is a DLL library and Sandbox will get it thru Hazel
		// Not NEEDED FOR STATIC LIBRARY Version of Hazel
		/* The linking ERRORs occur because those functions were not used in Hazel and no pointers to functions stored there either use those in Hazel or 
			or do the above declspec instrinsic to export and import dll function pointer so 
		*/
		ImGui::Begin("Sandbox Test");
		ImGui::Text("Welcome to HGenx 2021!");
		ImGui::End();
	
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