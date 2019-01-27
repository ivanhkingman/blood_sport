#include "Unit.h"

Unit::Unit(sf::Texture *texture, sf::RenderWindow *window) :
    _texture(texture),
    _window(window)
{
    _sprite.setTexture(*_texture);
    _sprite.setPosition(200, 100);
}

void Unit::setPosition(sf::Vector2i newPos)
{
    _position = newPos;
}

sf::Vector2i Unit::getPosition()
{
    return _position;
}

void Unit::drawSprite()
{
    _window->draw(_sprite);
}

