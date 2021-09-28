#pragma once

#include <iostream>
#include <tuple>

#include <ecs/ecs.hpp>

#include "../components/transform_component.h"

namespace ph
{

    class PhysicsSystem : public ecs::BaseSystem<PhysicsSystem>
    {
    public:
        using Signature = std::tuple<TransformComponent>;

        PhysicsSystem() = default;
        ~PhysicsSystem() = default;

        template<typename T>
        void update(T& comps)
        {
            for(ecs::EntityID entity : m_registered_entities)
            {
                TransformComponent& transform = comps.template get_component<TransformComponent>(entity);

                if (transform.position.x > 100000) {
                    transform.position.x -= 1;
                }
                else {
                    transform.position.x += 1;
                }
                transform.position.y += 1;
                transform.position.z += 1;

               // PH_CORE_INFO("phys process entity {}", entity);
            }
        }
    };
    
} // namespace ph
