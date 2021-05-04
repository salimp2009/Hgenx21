#pragma once
#include "Hgenx/Renderer/GraphicsContext.h"

namespace Hgenx
{
	class OpenGLContext:public GraphicsContext
	{
	public:
		virtual void Init() override;
		virtual void SwapBuffers() override;

		virtual ~OpenGLContext() = default;


	};







} // end of namespace
