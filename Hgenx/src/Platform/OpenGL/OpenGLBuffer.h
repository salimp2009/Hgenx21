#pragma once

#include "Hgenx/Renderer/Buffer.h"
 
namespace Hgenx
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* vertices, std::uint32_t size);
		virtual ~OpenGLVertexBuffer();

		virtual void Bind() const override;
		virtual void UnBind() const override;

		/*TODO; will be implemented */
		virtual const BufferLayout& GetLayout() const& override { return m_Layout; }
		virtual void SetLayout(const BufferLayout& layout) override { m_Layout = layout; }

	private:
		std::uint32_t m_RendererID;
		/*TODO!!*/
		BufferLayout m_Layout;
	};


	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(std::uint32_t* indices, std::uint32_t count);
		virtual ~OpenGLIndexBuffer();

		virtual void Bind() const override;
		virtual void UnBind() const override;

		virtual std::uint32_t GetCount() const override { return m_Count; }

	private:
		std::uint32_t m_RendererID;
		std::uint32_t m_Count;
	};


} // end of namespace