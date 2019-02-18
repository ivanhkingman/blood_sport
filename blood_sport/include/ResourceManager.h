#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>

#include <map>
#include <memory>

class ResourceManager {
    public:
        ResourceManager();
        void addTexture(std::string fileName, std::string textureName);
        sf::Texture& getTexture(std::string textureName);

    private:
        std::map<std::string, std::shared_ptr<sf::Texture>> m_textures;
};

#endif // RESOURCEMANAGER_H
