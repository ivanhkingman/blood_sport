#ifndef GAME_H
#define GAME_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <list>

#include "Unit.h"
#include <iostream>


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
        void handleKeyPress(sf::Keyboard::Key key);
        void handleKeyRelease(sf::Keyboard::Key key);
        void updateGame();

        sf::RenderWindow _window;
        std::list<sf::Sprite*> _sprites;

        bool _keyPressA;
        bool _keyPressD;
        bool _keyPressW;
        bool _keyPressS;

        sf::Texture _heroTexture;
        Unit _hero;
};

#endif // GAME_H
