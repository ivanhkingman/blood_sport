#ifndef UNIT_H
#define UNIT_H

#include <SFML/Graphics.hpp>


class Unit
{
    public:
        Unit(sf::Texture *texture, sf::RenderWindow *window);

        void setPosition(sf::Vector2i newPos);
        sf::Vector2i getPosition();

        void drawSprite();

    private:
        sf::Texture *_texture;
        sf::RenderWindow *_window;
        sf::Sprite _sprite;
        sf::Vector2i _position;
};

#endif // UNIT_H
