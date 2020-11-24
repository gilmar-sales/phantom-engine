#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <renderer/render_context.h>

namespace ph
{
	class OpenGLContext : public RenderContext
	{
	public:
		OpenGLContext(GLFWwindow* window_handle);

		virtual void init() override;
		virtual void swap_buffers() override;
	private:
		GLFWwindow* m_window_handle;
	};
}

