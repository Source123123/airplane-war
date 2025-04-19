#include "ResourceManager.hpp"
#include <stdexcept>

void ResourceManager::loadTexture(const std::string& name, const std::string& path) {
    std::string fullPath = getFullPath(path);
    if (!textures[name].loadFromFile(fullPath)) {
        throw std::runtime_error("Failed to load texture: " + fullPath);
    }
    if (!textures[name].loadFromFile(path)) {
        throw std::runtime_error("Failed to load texture: " + path);
    }
}

std::string ResourceManager::getFullPath(const std::string& filename) const {
    return assetsPath + filename;
}

void ResourceManager::setAssetsPath(const std::string& path) {
    assetsPath = path;
    if (!assetsPath.empty() && assetsPath.back() != '/') {
        assetsPath += '/';
    }
}

sf::Texture& ResourceManager::getTexture(const std::string& name) {
    return textures.at(name);
}

void ResourceManager::clearTextures() {
    textures.clear();
}