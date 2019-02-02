#ifndef MOVEMENTSYSTEM_H_INCLUDED
#define MOVEMENTSYSTEM_H_INCLUDED

#include "ECS.h"
#include "Components/Components.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class MovementSystem : ECSSystem {
public:
    MovementSystem(EntityManager* entityManager, InputManager* inputManager) :
        m_inputManager(inputManager),
        m_entityManager(entityManager)
        {}

    void update() override {
        auto entityList = m_entityManager->filterEntities<MovementSpeedComponent>();
        for(auto i : entityList) {
            if(i->hasComponent<SpriteComponent>() && i->hasComponent<PositionComponent>()) {
                auto& positionComp = i->getComponent<PositionComponent>();
                auto& spriteComp = i->getComponent<SpriteComponent>();
                auto& movementSpeedComp = i->getComponent<MovementSpeedComponent>();

                if(i->hasComponent<PlayableComponent>()) {
                    auto inputStates = m_inputManager->getKeyStates();
                    if(inputStates[sf::Keyboard::A]) positionComp.position -= sf::Vector2f(movementSpeedComp.movementSpeed ,0);
                    if(inputStates[sf::Keyboard::D]) positionComp.position += sf::Vector2f(movementSpeedComp.movementSpeed ,0);
                    if(inputStates[sf::Keyboard::W]) positionComp.position -= sf::Vector2f(0, movementSpeedComp.movementSpeed);
                    if(inputStates[sf::Keyboard::S]) positionComp.position += sf::Vector2f(0, movementSpeedComp.movementSpeed);
                    spriteComp.sprite.setPosition(positionComp.position);
                }
                else {
                    positionComp.position += sf::Vector2f(movementSpeedComp.movementSpeed ,0);
                    spriteComp.sprite.setPosition(positionComp.position);
                }
            }
        }
    }

private:
    InputManager* m_inputManager;
    EntityManager* m_entityManager;
};


#endif // MOVEMENTSYSTEM_H_INCLUDED
