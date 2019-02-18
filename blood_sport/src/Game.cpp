#include "Game.h"

const int Game::windowWidth     = 1400;
const int Game::windowHeight    = 800;
const int Game::frameRate       = 30;

Game::Game() :
    m_window(sf::VideoMode(windowWidth, windowHeight), "Blood Sport"),
    m_resourceManager(),
    m_inputManager(),
    m_entityManager(),
    m_spriteSys(&m_entityManager, &m_window),
    m_movementSys(&m_entityManager, &m_inputManager),
    m_collisionSys(&m_entityManager)
{
    m_spriteSys.drawCollisionBoxes(true);
    // Create a unit
    m_resourceManager.addTexture("testImage.png", "Hero");
    m_entityManager.addEntity<UnitEntity>(&m_resourceManager.getTexture("Hero"));

    m_entityManager.addEntity<PathBlockerEntity>(0, 0, windowWidth, 10);
    m_entityManager.addEntity<PathBlockerEntity>(0, windowHeight-10, windowWidth, 10);
    m_entityManager.addEntity<PathBlockerEntity>(0, 0, 10, windowHeight);
    m_entityManager.addEntity<PathBlockerEntity>(windowWidth-10, 0, 10, windowHeight);

    m_entityManager.addEntity<PathBlockerEntity>(500, 500, 100, 100);

}

void Game::start() {

    sf::Time timePerFrameMS = sf::milliseconds(1000/float(frameRate));

    sf::Clock gameClock;
    while(m_window.isOpen()) {
        gameClock.restart();

        handleEvents();

        m_window.clear();
        // -- Render loop --
        m_movementSys.update();
        m_collisionSys.update();
        m_spriteSys.update();
        m_window.display();


        sf::Time timeToNextFrame = timePerFrameMS - gameClock.getElapsedTime();
        if(timeToNextFrame > sf::milliseconds(0)) {
            sf::sleep(timeToNextFrame);
        }
        //std::cout << "Frame update" << std::endl;
    }
}


void Game::handleEvents() {
    sf::Event event;
    while(m_window.pollEvent(event)) {
        if(event.type == sf::Event::Closed) {
            m_window.close();
        }
        else if(event.type == sf::Event::KeyPressed) {
            m_inputManager.keyPress(event);
        }
        else if(event.type == sf::Event::KeyReleased) {
            m_inputManager.keyRelease(event);
        }
    }
}

