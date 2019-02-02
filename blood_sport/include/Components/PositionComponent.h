#ifndef POSITIONCOMPONENT_H_INCLUDED
#define POSITIONCOMPONENT_H_INCLUDED

#include "ECS.h"
#include "SFML/System.hpp"

class PositionComponent : public Component {
public:
    sf::Vector2f position;

    PositionComponent(float x, float y) : position(x, y) {}

    void update() override {}

};

#endif // POSITIONCOMPONENT_H_INCLUDED
