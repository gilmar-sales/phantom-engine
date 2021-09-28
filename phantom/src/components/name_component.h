#pragma once

#include <glm/glm.hpp>

namespace ph
{
    struct NameComponent
    {
       std::string name;

		NameComponent() = default;
		NameComponent(const NameComponent&) = default;
		NameComponent(const std::string& name)
			: name(name) {}
    };
    
} // namespace ecs
