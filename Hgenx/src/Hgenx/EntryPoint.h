#pragma once

#ifdef HG_PLATFORM_WINDOWS
extern Hgenx::Application* Hgenx::CreateApplication();

int main(int argc, char** argv)
{
	Hgenx::Log::Init();
	Hgenx::Log::GetCoreLogger()->warn("Initialize Log");
	Hgenx::Log::GetClientLogger()->info("Initialize Log");
	auto app = Hgenx::CreateApplication();
	app->Run();
	delete app;
}

#endif 