#ifndef GAME_H
#define GAME_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <map>
#include <iostream>
#include <memory>

#include "ECS.h"
#include "ResourceManager.h"
#include "InputManager.h"

#include "Components/Components.h"
#include "Entities/UnitEntity.h"
#include "Systems/Systems.h"


class Game
{
    public:
        Game();

        void start();

        static const int windowWidth;
        static const int windowHeight;
        static const int frameRate;

    private:
        void handleEvents();

        sf::RenderWindow m_window;

        ResourceManager m_resourceManager;
        InputManager m_inputManager;
        EntityManager m_entityManager;

        SpriteSystem m_spriteSys;
        MovementSystem m_movementSys;
};

#endif // GAME_H
