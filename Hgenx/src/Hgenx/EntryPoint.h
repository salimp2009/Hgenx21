#pragma once

#ifdef HG_PLATFORM_WINDOWS
extern Hgenx::Application* Hgenx::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Hgenx::CreateApplication();
	app->Run();
	delete app;
}

#endif 