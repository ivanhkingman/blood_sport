#include <SFML/Graphics.hpp>
#include <vector>
#include "Unit.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Blood Sport");

    sf::Texture texture;
    if(!texture.loadFromFile("testImage.png"))
    {
        return -1;
    }

    Unit myUnit(&texture, &window);

    std::vector<Unit*> units;
    units.push_back(&myUnit);

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {

            switch(event.type) {

            case sf::Event::Closed:
                window.close();
                break;

            default:
                break;
            }

        }

        window.clear();

        // -- Render loop --

        for(std::vector<Unit*>::iterator iter = units.begin(); iter != units.end(); ++iter) {
            (*iter)->drawSprite();
        }

        window.display();
    }

    return 0;
}
