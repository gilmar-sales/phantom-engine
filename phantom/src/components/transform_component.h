#pragma once

#include <glm/glm.hpp>

namespace ecs
{
    struct TransformComponent
    {
        glm::vec3 position;
        glm::vec3 scale;
    };
    
} // namespace ecs
