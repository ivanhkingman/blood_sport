#include "InputManager.h"

InputManager::InputManager() {

    typedef sf::Keyboard key;

    m_keyStates[key::A] = false;
    m_keyStates[key::D] = false;
    m_keyStates[key::W] = false;
    m_keyStates[key::S] = false;
}

void InputManager::keyPress(sf::Event keyEvent) {
    m_keyStates[keyEvent.key.code] = true;
}

void InputManager::keyRelease(sf::Event keyEvent) {
    m_keyStates[keyEvent.key.code] = false;
}

std::map<sf::Keyboard::Key, bool> InputManager::getKeyStates() {
    return m_keyStates;
}
