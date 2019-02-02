#ifndef UNITENTITY_H_INCLUDED
#define UNITENTITY_H_INCLUDED

#include "ECS.h"
#include <SFML/Graphics.hpp>
#include <Components/Components.h>

class UnitEntity : public Entity {
public:
    UnitEntity(sf::Texture* texture) {
        this->addComponent<SpriteComponent>(texture);
        this->addComponent<PlayableComponent>();
        this->addComponent<PositionComponent>(200, 200);
        this->addComponent<MovementSpeedComponent>(10);
    }
};

#endif // UNITENTITY_H_INCLUDED
