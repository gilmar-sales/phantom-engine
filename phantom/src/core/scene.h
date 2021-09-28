#pragma once

#include "log.h"

#include <components/mesh_component.h>
#include <components/name_component.h>
#include <components/transform_component.h>
#include <ecs/ecs.hpp>
#include <systems/physics_system.h>
#include <tags/tags.h>


namespace ph
{
using ComponentList = std::tuple<NameComponent, TransformComponent, MeshComponent>;
using TagList = std::tuple<PlayerTag>;
using SystemList = std::tuple<PhysicsSystem>;
using Settings = ecs::Settings<ComponentList, TagList, SystemList>;

class Scene
{
  public:
    Scene() = default;
    ~Scene() = default;

    void update();

    ecs::Manager<Settings> m_manager;
};
} // namespace ph