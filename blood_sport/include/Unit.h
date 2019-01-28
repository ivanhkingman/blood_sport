#ifndef UNIT_H
#define UNIT_H

#include <SFML/Graphics.hpp>


class Unit
{
    public:
        Unit();
        Unit(sf::Texture *texture);

        void setTexture(sf::Texture *texture);
        sf::Sprite getSprite();

        void setPosition(sf::Vector2f newPosition);
        sf::Vector2f getPosition();


    private:
        sf::Texture *_texture;
        sf::Sprite _sprite;
        sf::Vector2f _position;
};

#endif // UNIT_H
