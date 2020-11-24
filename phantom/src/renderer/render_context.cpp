#include <phpch.h>

#include "render_context.h"

#include "renderer.h"
#include <platform/opengl/opengl_context.h>

namespace ph
{
	std::unique_ptr<RenderContext> RenderContext::create(void* window)
	{
		switch (Renderer::get_api())
		{
		case RendererAPI::API::None:    PH_CORE_ERROR("RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return std::make_unique<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		PH_CORE_ERROR("Unknown RendererAPI!");
		return nullptr;
	}
}
