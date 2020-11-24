#pragma once

#include "renderer_api.h"

namespace ph
{
	class Renderer
	{
	public:
		static void init();
		static void shutdown();

		static void on_window_resize(uint32_t width, uint32_t height);

		static RendererAPI::API get_api() { return RendererAPI::get_api(); }
	};
}

