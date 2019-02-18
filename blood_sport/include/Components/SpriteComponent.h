#ifndef SPRITECOMPONENT_H_INCLUDED
#define SPRITECOMPONENT_H_INCLUDED

#include "ECS.h"
#include <SFML/Graphics.hpp>

namespace ComponentType {

    class Sprite : public Component {
    public:
        sf::Sprite sprite;

        Sprite(sf::Texture* texture) {
            _texture = texture;
            sprite.setTexture(*_texture);
            sprite.setPosition(0, 0);
        }

    private:
        sf::Texture* _texture;

    };
}

#endif // SPRITECOMPONENT_H_INCLUDED
