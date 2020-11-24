#pragma once

#include <memory>

#include <glm/glm.hpp>
#include <glm/glm.hpp>

namespace ph
{
	class RendererAPI
	{
	public:
		enum class API
		{
			None = 0, OpenGL = 1
		};

		virtual void init() = 0;
		virtual void set_viewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
		virtual void set_clear_color(const glm::vec4& color) = 0;
		virtual void clear() = 0;

		virtual void draw_indexed(const std::shared_ptr<std::vector<glm::vec3>>& vertexArray, uint32_t indexCount = 0) = 0;

		static API get_api() { return s_api; }
		static std::unique_ptr<RendererAPI> create();
	private:
		static API s_api;
	};
}
