#pragma once
#include "Hgenx/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Hgenx
{
	
	class OpenGLContext:public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);
		virtual void Init() override;
		virtual void SwapBuffers() override;

		virtual ~OpenGLContext() = default;
	private:

		GLFWwindow* m_WindowHandle;
	};



} // end of namespace
