#pragma once

#include <memory>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <ecs/ecs.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <core/log.h>
#include <components/mesh_component.h>

namespace ph
{
	struct Vertex {
		glm::vec3 position;
		glm::vec3 normal;
		glm::vec2 texture_coords;
		glm::vec3 tangent;
		glm::vec3 bitangent;
	};

	class ModelLoader
	{
	public:
		void load(std::string path);
		void processNode(aiNode* node, const aiScene* scene);

		MeshComponent processMesh(aiMesh *mesh, const aiScene *scene);

		// initializes all the buffer objects/arrays
		MeshComponent setup_mesh(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices);

		static std::unique_ptr<ModelLoader>& get_instance()
		{
			return s_instance;
		}

	private:
		std::vector<MeshComponent> meshes;
		static std::unique_ptr<ModelLoader> s_instance;
	};
} // namespace ph