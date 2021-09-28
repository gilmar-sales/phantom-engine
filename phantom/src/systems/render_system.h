#pragma once

#include <iostream>
#include <tuple>

#include <ecs/ecs.hpp>

#include "../components/transform_component.h"
#include "../components/mesh_component.h"

namespace ph
{

    class RenderSystem : public ecs::BaseSystem<RenderSystem>
    {
    public:
        using Signature = std::tuple<TransformComponent, MeshComponent>;

        RenderSystem() = default;
        ~RenderSystem() = default;

        template<typename T>
        void update(T& comps)
        {
            for(ecs::EntityID entity : m_registered_entities)
            {
                TransformComponent& transform = comps.template get_component<TransformComponent>(entity);
                MeshComponent& mesh = comps.template get_component<MeshComponent>(entity);

               
            }
        }
    };
    
} // namespace ph
