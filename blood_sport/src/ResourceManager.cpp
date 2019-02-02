#include "ResourceManager.h"

ResourceManager::ResourceManager() {
    //constructor
}

void ResourceManager::addTexture(std::string fileName, std::string textureName) {
    m_textures[textureName] = std::make_shared<sf::Texture>();
    m_textures[textureName]->loadFromFile(fileName);
}

sf::Texture& ResourceManager::getTexture(std::string textureName) {
    return *m_textures[textureName].get();
}
