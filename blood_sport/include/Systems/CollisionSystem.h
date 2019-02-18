#ifndef COLLISIONSYSTEM_H_INCLUDED
#define COLLISIONSYSTEM_H_INCLUDED

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "ECS.h"
#include "Components/Components.h"

class CollisionSystem : ECSSystem {
public:
    CollisionSystem(EntityManager* manager) :
        m_manager(manager)
        {}

    void update() {
        // Simple O(n^2) collision detection - consider replacing in the future if performance scales poorly
        auto entityList = m_manager->filterEntities<ComponentType::Collision>();
        for(auto entity : entityList) {
            auto& collisionComp = entity->getComponent<ComponentType::Collision>();
            auto& positionComp = entity->getComponent<ComponentType::Position>();
            auto& shapeComp = entity->getComponent<ComponentType::ShapeRect>();
            auto& spriteComp = entity->getComponent<ComponentType::Sprite>();

            sf::Vector2f upperLeftCoordinate = positionComp.position;
            sf::Vector2f lowerRightCoordinate = upperLeftCoordinate +
                                                sf::Vector2f(shapeComp.width, shapeComp.height);

            auto shapeEntityList = m_manager->filterEntities<ComponentType::ShapeRect>();
            for(auto shapeEntity : shapeEntityList) {
                if(entity == shapeEntity) continue;

                auto shapePositionComp = shapeEntity->getComponent<ComponentType::Position>();
                auto shapeShapeComp = shapeEntity->getComponent<ComponentType::ShapeRect>();

                sf::Vector2f shapeUpperLeftCoordinate = shapePositionComp.position;
                sf::Vector2f shapeLowerRightCoordinate = shapeUpperLeftCoordinate +
                                                        sf::Vector2f(shapeShapeComp.width, shapeShapeComp.height);

                bool isColliding = checkRectangleOverlap(upperLeftCoordinate, lowerRightCoordinate,
                                                         shapeUpperLeftCoordinate, shapeLowerRightCoordinate);

                if(!isColliding) continue;

                sf::Vector2f shift = calculateShift(upperLeftCoordinate, lowerRightCoordinate,
                                                    shapeUpperLeftCoordinate, shapeLowerRightCoordinate);

                positionComp.position = calculateNewPosition(positionComp.position,
                                                             positionComp.previousPosition,
                                                             shift);
            }
        }
    }

private:
    EntityManager* m_manager;

    bool checkRectangleOverlap(sf::Vector2f upperLeftCoordinateA, sf::Vector2f lowerRightCoordinateA,
                               sf::Vector2f upperLeftCoordinateB, sf::Vector2f lowerRightCoordinateB)
    {
        if(upperLeftCoordinateA.x > lowerRightCoordinateB.x || upperLeftCoordinateB.x > lowerRightCoordinateA.x) return false;
        if(upperLeftCoordinateA.y > lowerRightCoordinateB.y || upperLeftCoordinateB.y > lowerRightCoordinateA.y) return false;

        return true;

    }

    sf::Vector2f calculateShift(sf::Vector2f upperLeftCoordinateA, sf::Vector2f lowerRightCoordinateA,
                                sf::Vector2f upperLeftCoordinateB, sf::Vector2f lowerRightCoordinateB)
    {
        float widthA = lowerRightCoordinateA.x - upperLeftCoordinateA.x;
        float heightA = lowerRightCoordinateA.y - upperLeftCoordinateA.y;

        float widthB = lowerRightCoordinateB.x - upperLeftCoordinateB.x;
        float heightB = lowerRightCoordinateB.y - upperLeftCoordinateB.y;

        sf::Vector2f centerA = upperLeftCoordinateA;
        centerA.x += widthA/2.0;
        centerA.y += heightA/2.0;

        sf::Vector2f centerB = upperLeftCoordinateB;
        centerB.x += widthB/2.0;
        centerB.y += heightB/2.0;

        sf::Vector2f centerOffset;

        centerOffset.x = std::abs(centerA.x - centerB.x);
        centerOffset.y = std::abs(centerA.y - centerB.y);

        sf::Vector2f shift;

        shift.x = (widthA + widthB)/2.0 - centerOffset.x;
        shift.y = (heightA + heightB)/2.0 - centerOffset.y;

        return shift;
    }

    sf::Vector2f calculateNewPosition(sf::Vector2f position, sf::Vector2f previousPosition, sf::Vector2f shift) {
        sf::Vector2f prevStep = position - previousPosition;
        sf::Vector2f newStep;

        if(shift.x < shift.y) {
            if(prevStep.x > 0)      newStep.x = prevStep.x - shift.x - 1;
            else if(prevStep.x < 0) newStep.x = prevStep.x + shift.x + 1;
        } else {
            if(prevStep.y > 0)      newStep.y = prevStep.y - shift.y - 1;
            else if(prevStep.y < 0) newStep.y = prevStep.y + shift.y + 1;
        }

        return previousPosition + newStep;
    }
};

#endif // COLLISIONSYSTEM_H_INCLUDED
