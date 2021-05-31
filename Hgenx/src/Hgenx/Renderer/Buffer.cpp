#include "hgpch.h"
#include "Hgenx/Renderer/Buffer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"
#include "Hgenx/Renderer/Renderer.h"


namespace Hgenx
{

	VertexBuffer* VertexBuffer::Create(float* vertices, std::uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None:		HG_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
			case RendererAPI::OpenGL:	return new OpenGLVertexBuffer(vertices, size);
			
			/*TODO::*/
			//case RendererAPI::OpenGL:	return CreateRef<OpenGLVertexBuffer>(vertices, size);  // NOTE: if used change the return type Ref<VertexBuffer>
			/* ADD more RendererAPI for Vulkan and DirectX*/
		}
		HG_CORE_ASSERT(false, "Unkown Renderer!")
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(std::uint32_t* indices, std::uint32_t count)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None:		HG_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::OpenGL:	return new OpenGLIndexBuffer(indices, count);
			/*TODO::*/
			//case RendererAPI::OpenGL:	return CreateRef<OpenGLIndexBuffer>(indices, count); // NOTE: if used change the return type Ref<IndexBuffer>
			/* ADD more RendererAPI for Vulkan and DirectX*/
		}
		HG_CORE_ASSERT(false, "Unkown Renderer!")
		return nullptr;
	}

}