#include "Game.h"

const int Game::windowWidth     = 800;
const int Game::windowHeight    = 600;
const int Game::frameRate       = 30;

Game::Game() :
    _window(sf::VideoMode(windowWidth, windowHeight), "Blood Sport"),
    _keyPressA(false), _keyPressD(false), _keyPressW(false), _keyPressS(false),
    _heroTexture(), _hero()
{
    // Create a unit
    _heroTexture.loadFromFile("testImage.png");
    _hero.setTexture(&_heroTexture);
}

void Game::start() {



    float timePerFrameMS = 1000/float(frameRate);

    sf::Clock gameClock;
    while(_window.isOpen()) {
        gameClock.restart();

        handleEvents();
        updateGame();

        _window.clear();
        // -- Render loop --
        _window.draw(_hero.getSprite());
        _window.display();

        while(gameClock.getElapsedTime().asMilliseconds() <= timePerFrameMS) {
        }
    }
}


void Game::handleEvents() {
    sf::Event event;
    while(_window.pollEvent(event)) {
        switch(event.type) {
            case sf::Event::Closed:
                _window.close();
                break;

            case sf::Event::KeyPressed:
                handleKeyPress(event.key.code);
                break;

            case sf::Event::KeyReleased:
                handleKeyRelease(event.key.code);
                break;

            default:
                break;
        }
    }
}


void Game::handleKeyPress(sf::Keyboard::Key key) {
    if(key == sf::Keyboard::A)      _keyPressA = true;
    else if(key == sf::Keyboard::D) _keyPressD = true;
    else if(key == sf::Keyboard::W) _keyPressW = true;
    else if(key == sf::Keyboard::S) _keyPressS = true;
}

void Game::handleKeyRelease(sf::Keyboard::Key key) {
    if     (key == sf::Keyboard::A) _keyPressA = false;
    else if(key == sf::Keyboard::D) _keyPressD = false;
    else if(key == sf::Keyboard::W) _keyPressW = false;
    else if(key == sf::Keyboard::S) _keyPressS = false;
}

void Game::updateGame() {
    if(_keyPressA)  _hero.setPosition(_hero.getPosition() + sf::Vector2f(-20,0));
    if(_keyPressD)  _hero.setPosition(_hero.getPosition() + sf::Vector2f(20,0));
    if(_keyPressW)  _hero.setPosition(_hero.getPosition() + sf::Vector2f(0,-20));
    if(_keyPressS)  _hero.setPosition(_hero.getPosition() + sf::Vector2f(0,20));
}
