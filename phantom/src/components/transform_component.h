#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace ph
{
    struct TransformComponent
    {
        glm::vec3 position;
        glm::vec3 scale;
        glm::quat rotation;
    };
    
} // namespace ecs
