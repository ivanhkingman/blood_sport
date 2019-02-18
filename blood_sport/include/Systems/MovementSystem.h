#ifndef MOVEMENTSYSTEM_H_INCLUDED
#define MOVEMENTSYSTEM_H_INCLUDED

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "ECS.h"
#include "Components/Components.h"

class MovementSystem : ECSSystem {
public:
    MovementSystem(EntityManager* entityManager, InputManager* inputManager) :
        m_inputManager(inputManager),
        m_entityManager(entityManager)
        {}

    void update() override {
        auto entityList = m_entityManager->filterEntities<ComponentType::MovementSpeed>();
        for(auto entity : entityList) {
            if(entity->hasComponent<ComponentType::Sprite>() && entity->hasComponent<ComponentType::Position>()) {
                auto& positionComp = entity->getComponent<ComponentType::Position>();
                auto& spriteComp = entity->getComponent<ComponentType::Sprite>();
                auto& movementSpeedComp = entity->getComponent<ComponentType::MovementSpeed>();

                positionComp.previousPosition = positionComp.position;

                if(entity->hasComponent<ComponentType::Playable>()) {
                    auto inputStates = m_inputManager->getKeyStates();
                    if(inputStates[sf::Keyboard::A]) positionComp.position -= sf::Vector2f(movementSpeedComp.movementSpeed ,0);
                    if(inputStates[sf::Keyboard::D]) positionComp.position += sf::Vector2f(movementSpeedComp.movementSpeed ,0);
                    if(inputStates[sf::Keyboard::W]) positionComp.position -= sf::Vector2f(0, movementSpeedComp.movementSpeed);
                    if(inputStates[sf::Keyboard::S]) positionComp.position += sf::Vector2f(0, movementSpeedComp.movementSpeed);
                }
                else {
                    positionComp.position += sf::Vector2f(movementSpeedComp.movementSpeed, 0);
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
