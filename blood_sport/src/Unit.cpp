#include "Unit.h"

Unit::Unit() :
    _position(200, 100)
{}

Unit::Unit(sf::Texture *texture) :
    _texture(texture),
    _position(200, 100)
{
    _sprite.setTexture(*_texture);
    _sprite.setPosition(200, 100);
}

void Unit::setTexture(sf::Texture *texture)
{
    _texture = texture;
    _sprite.setTexture(*texture);
    _sprite.setPosition(200, 100);
}

void Unit::setPosition(sf::Vector2f newPosition)
{
    _position = newPosition;
    _sprite.setPosition(newPosition);
}

sf::Vector2f Unit::getPosition()
{
    return _position;
}

sf::Sprite Unit::getSprite()
{
    return _sprite;
}

