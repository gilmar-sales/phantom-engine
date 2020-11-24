#include <phpch.h>

#include "opengl_context.h"

namespace ph
{
	OpenGLContext::OpenGLContext(GLFWwindow* window_handle) : m_window_handle(window_handle)
	{
		if (!window_handle)
			PH_CORE_ERROR("Window Handle is null!");
	}

	void OpenGLContext::init()
	{
		glfwMakeContextCurrent(m_window_handle);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			PH_CORE_ERROR("Couldn't initialize GLAD!");
		else
			PH_CORE_INFO("GLAD initialized!");

		PH_CORE_INFO("OpenGL Info:");
		PH_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		PH_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		PH_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

		if(!(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 1)))
			PH_CORE_ERROR( "Phantom requires at least OpenGL version 4.1!");
	}

	void OpenGLContext::swap_buffers()
	{
		glfwSwapBuffers(m_window_handle);
	}
}
