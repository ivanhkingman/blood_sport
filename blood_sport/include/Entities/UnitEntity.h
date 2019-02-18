#ifndef UNITENTITY_H_INCLUDED
#define UNITENTITY_H_INCLUDED

#include "ECS.h"
#include <SFML/Graphics.hpp>
#include <Components/Components.h>

class UnitEntity : public Entity {
public:
    UnitEntity(sf::Texture* texture) {
        this->addComponent<ComponentType::Sprite>(texture);
        this->addComponent<ComponentType::ShapeRect>(250, 340);
        this->addComponent<ComponentType::Playable>();
        this->addComponent<ComponentType::Position>(200, 300);
        this->addComponent<ComponentType::MovementSpeed>(20);
        this->addComponent<ComponentType::Collision>();
    }
};

#endif // UNITENTITY_H_INCLUDED
