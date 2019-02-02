#include "Game.h"

#include "ECS.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Systems/SpriteSystem.h"
#include "Systems/MovementSystem.h"

int main()
{
    Game myGame;
    myGame.start();

    return 0;
}
