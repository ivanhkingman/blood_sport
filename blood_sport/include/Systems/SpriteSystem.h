#ifndef SPRITESYSTEM_H_INCLUDED
#define SPRITESYSTEM_H_INCLUDED

#include "ECS.h"
#include "Components/Components.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class SpriteSystem : ECSSystem {
public:
    SpriteSystem(EntityManager* manager, sf::RenderWindow* window) :
        m_manager(manager), m_window(window) {}

    void update() {
        auto entityList = m_manager->filterEntities<SpriteComponent>();
        for(auto i : entityList) {
            auto component = i->getComponent<SpriteComponent>();
            m_window->draw(component.sprite);
        }
    }

private:
    EntityManager* m_manager;
    sf::RenderWindow* m_window;
};

#endif // SPRITESYSTEM_H_INCLUDED
