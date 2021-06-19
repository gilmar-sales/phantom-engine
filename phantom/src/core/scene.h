#pragma once

#include "log.h"

#include <ecs/ecs.hpp>
#include <components/transform_component.h>
#include <components/name_component.h>
#include <tags/tags.h>
#include <systems/physics_system.h>

namespace ph
{
    using ComponentList = std::tuple<ecs::NameComponent, ecs::TransformComponent>;
    using TagList = std::tuple<ecs::PlayerTag>;
    using SystemList = std::tuple<ecs::PhysicsSystem>;
    using Settings = ecs::Settings<ComponentList, TagList, SystemList>;

    class Scene 
    {
        public:
            Scene() = default;
            ~Scene() = default;

            void update();

        ecs::Manager<Settings> m_manager;
    };
}