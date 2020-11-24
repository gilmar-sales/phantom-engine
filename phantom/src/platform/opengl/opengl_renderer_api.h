#pragma once

#include <glad/glad.h>
#include <renderer/renderer_api.h>

namespace ph
{
	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		OpenGLRendererAPI() = default;

		virtual void init() override;
		virtual void set_viewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;

		virtual void set_clear_color(const glm::vec4& color) override;
		virtual void clear() override;

		virtual void draw_indexed(const std::shared_ptr<std::vector<glm::vec3>>& vertexArray, uint32_t indexCount = 0) override;
	};
}

