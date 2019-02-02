#ifndef SPRITECOMPONENT_H_INCLUDED
#define SPRITECOMPONENT_H_INCLUDED

#include "ECS.h"
#include <SFML/Graphics.hpp>

class SpriteComponent : public Component {
public:
    sf::Sprite sprite;

    SpriteComponent(sf::Texture* texture) {
        _texture = texture;
        sprite.setTexture(*_texture);
        sprite.setPosition(0, 0);
    }

    void update() override {}

private:
    sf::Texture* _texture;


};

#endif // SPRITECOMPONENT_H_INCLUDED
