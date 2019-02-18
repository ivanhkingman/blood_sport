#ifndef POSITIONCOMPONENT_H_INCLUDED
#define POSITIONCOMPONENT_H_INCLUDED

#include "ECS.h"
#include "SFML/System.hpp"

namespace ComponentType {

    class Position : public Component {
    public:
        sf::Vector2f position;
        sf::Vector2f previousPosition;

        Position(float x, float y) :
            position(x, y),
            previousPosition(x, y)
            {}

    };
}
#endif // POSITIONCOMPONENT_H_INCLUDED
