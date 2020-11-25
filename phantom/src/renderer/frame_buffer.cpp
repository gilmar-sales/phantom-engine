#include <phpch.h>

#include "frame_buffer.h"

#include <renderer/renderer.h>

#include <platform/opengl/opengl_frame_buffer.h>

namespace ph {

	std::shared_ptr<Framebuffer> Framebuffer::create(const FramebufferSpecification& spec)
	{
		switch (Renderer::get_api())
		{
		case RendererAPI::API::None:    PH_CORE_ERROR("RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return std::make_shared<OpenGLFramebuffer>(spec);
		default: PH_CORE_ERROR("Unknown RendererAPI!");
		}

		return nullptr;
	}

}