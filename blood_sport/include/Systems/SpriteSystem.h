#ifndef SPRITESYSTEM_H_INCLUDED
#define SPRITESYSTEM_H_INCLUDED

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "ECS.h"
#include "Components/Components.h"

class SpriteSystem : ECSSystem {
public:
    SpriteSystem(EntityManager* manager, sf::RenderWindow* window) :
        m_manager(manager),
        m_window(window),
        m_drawCollisionBoxesOn(false)
        {}

    void drawCollisionBoxes(bool draw) {
        m_drawCollisionBoxesOn = draw;
    }

    void update() {
        // Draw sprites
        auto entityList = m_manager->filterEntities<ComponentType::Sprite>();
        for(auto entity : entityList) {
            auto& spriteComp = entity->getComponent<ComponentType::Sprite>();
            auto positionComp = entity->getComponent<ComponentType::Position>();

            spriteComp.sprite.setPosition(positionComp.position);
            m_window->draw(spriteComp.sprite);
        }
        // Draw collision box
        if(m_drawCollisionBoxesOn) {
            auto entityList = m_manager->filterEntities<ComponentType::ShapeRect>();
            for(auto entity : entityList) {
                drawCollisionBoxes(entity);
            }
        }
    }

private:
    EntityManager* m_manager;
    sf::RenderWindow* m_window;
    bool m_drawCollisionBoxesOn;

    void drawCollisionBoxes(Entity* entity) {
        if(entity->hasComponent<ComponentType::Position>()) {
            auto shapeComp = entity->getComponent<ComponentType::ShapeRect>();
            auto positionComp = entity->getComponent<ComponentType::Position>();

            sf::RectangleShape collisionShape(sf::Vector2f(shapeComp.width, shapeComp.height));
            collisionShape.setPosition(positionComp.position);
            collisionShape.setFillColor(sf::Color(100, 250, 50, 150));

            m_window->draw(collisionShape);
        }
    }
};

#endif // SPRITESYSTEM_H_INCLUDED
