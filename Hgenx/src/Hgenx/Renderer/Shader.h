#pragma once

#include <string>
//#include <cstdint>

namespace Hgenx
{

	class Shader
	{
	public:
		Shader() = default;
		/* TODO: will be refactored to receive a filename rather than the string!!*/
		Shader(const std::string& vertexSrc, std::string& fragmentSrc);

		~Shader();

		void Bind() const;
		void UnBind() const;

	private:
		std::uint32_t m_RendererID;

	};


} // end of namespace
