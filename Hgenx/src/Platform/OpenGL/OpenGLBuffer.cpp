#include "hgpch.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

#include <glad/glad.h>

namespace Hgenx
{
/////////////////////////////////////////////////////////////////////////////////
///// VERTEX BUFFER /////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////


	OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint32_t size): m_RendererID{0}
	{
		glCreateBuffers(1, &m_RendererID);
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}
	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &m_RendererID);
	}

	void OpenGLVertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	}

	void OpenGLVertexBuffer::UnBind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}


/////////////////////////////////////////////////////////////////////////////////
///// INDEX BUFFER /////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices, uint32_t count): m_RendererID{0}, m_Count{0}
	{
		
		
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
	}

	void OpenGLIndexBuffer::Bind() const
	{
		
	}

	void OpenGLIndexBuffer::UnBind() const
	{
	}

	uint32_t OpenGLIndexBuffer::GetCount() const
	{
		return uint32_t();
	}

}