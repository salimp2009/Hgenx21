
#include "hgpch.h"
#include "WindowsInput.h"

#include "Hgenx/Application.h"
#include <GLFW/glfw3.h>


namespace Hgenx
{
	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::IsKeyPressedImpl(int keycode)
	{
		auto window =static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keycode);

		return state == GLFW_PRESS || state ==GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int button)
	{
		return false;
	}

	std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{
		return std::pair<float, float>();
	}

	float WindowsInput::GetMouseXImpl()
	{
		return 0.0f;
	}

	float WindowsInput::GetMouseYImpl()
	{
		return 0.0f;
	}


}


