#include "ResourceManager.hpp"
#include <stdexcept>

void ResourceManager::loadTexture(const std::string& name, const std::string& path) {
    std::string fullPath = getFullPath(path);
    if (!textures[name].loadFromFile(fullPath)) {
        throw std::runtime_error("Failed to load texture: " + fullPath);
    }
}



sf::Texture& ResourceManager::getTexture(const std::string& name) {
    return textures.at(name);
}

void ResourceManager::clearTextures() {
    textures.clear();
}