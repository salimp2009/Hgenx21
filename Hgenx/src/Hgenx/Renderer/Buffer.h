#pragma once

namespace Hgenx
{
	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		/*TODO; will be implemented */
		//virtual const BufferLayout& GetLayout() const& = 0;
		//virtual void SetLayout(const BufferLayout& layout) = 0;

		/*TODO; Will be implemented*/
		static VertexBuffer* Create(float* vertices, std::uint32_t size);
		//static Ref<VertexBuffer> Create(float* vertices, uint32_t size);

	};

	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual std::uint32_t GetCount() const = 0;

		/*TODO; Will be implemented*/
		static IndexBuffer* Create(std::uint32_t* indices, std::uint32_t count);
		//static Ref<IndexBuffer> Create(uint32_t* indices, uint32_t count);  //TODO: Change above to Ref<> (shared pointer)

	};




} // endof namespace