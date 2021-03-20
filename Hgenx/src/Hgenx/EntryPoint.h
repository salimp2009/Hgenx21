#pragma once


#ifdef HG_PLATFORM_WINDOWS
extern Hgenx::Application* Hgenx::CreateApplication();

int main(int argc, char** argv)
{
	Hgenx::Log::Init();
	HG_CORE_WARN("Initialize Log");
	int a = 10;
	HG_INFO("Hello!!! Variable={0}", a);
	//HG_CORE_FATAL("Fatal");
	//HG_CORE_TRACE_LAMBDA("lambda works  Variable = {0} ", 1);
	
	auto app = Hgenx::CreateApplication();
	app->Run();
	delete app;
}

#endif 