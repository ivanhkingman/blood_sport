#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SFML/Window.hpp>

#include <map>

class InputManager
{
    public:
        InputManager();
        void keyPress(sf::Event keyEvent);
        void keyRelease(sf::Event keyEvent);

        std::map<sf::Keyboard::Key, bool> getKeyStates();

    private:
        std::map<sf::Keyboard::Key, bool> m_keyStates;
};

#endif // INPUTMANAGER_H
