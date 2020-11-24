#pragma once

namespace ph
{
	class RenderContext
	{
	public:
		virtual ~RenderContext() = default;

		virtual void init() = 0;
		virtual void swap_buffers() = 0;

		static std::unique_ptr<RenderContext> create(void* window);
	};
}