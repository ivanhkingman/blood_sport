#ifndef PATHBLOCKERENTITY_H_INCLUDED
#define PATHBLOCKERENTITY_H_INCLUDED

#include "ECS.h"
#include <SFML/Graphics.hpp>
#include <Components/Components.h>

class PathBlockerEntity : public Entity {
public:
    PathBlockerEntity(float x, float y, float width, float height) {
        this->addComponent<ComponentType::ShapeRect>(width, height);
        this->addComponent<ComponentType::Position>(x, y);
    }
};

#endif // PATHBLOCKERENTITY_H_INCLUDED
