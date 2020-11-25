#include <phpch.h>

#include "renderer_api.h"

#include <platform/OpenGL/opengl_renderer_api.h>

namespace ph
{
	RendererAPI::API RendererAPI::s_api = RendererAPI::API::OpenGL;

	std::shared_ptr<RendererAPI> RendererAPI::create()
	{
		switch (s_api)
		{
		case RendererAPI::API::None:    PH_CORE_ERROR("RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return std::make_shared<OpenGLRendererAPI>();
		}

		PH_CORE_ERROR("Unknown RendererAPI!");
		return nullptr;
	}

	std::shared_ptr<RendererAPI> RendererAPI::s_instance = create();
}