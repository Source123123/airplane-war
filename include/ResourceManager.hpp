#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>

class ResourceManager {
private:
    std::unordered_map<std::string, sf::Texture> textures;
    std::string assetsPath = "resources/";

public:
    ResourceManager() = default;

public:
    void setAssetsPath(const std::string& path) { assetsPath = path; }
    std::string getFullPath(const std::string& filename) const { return assetsPath + filename; }
    
public:
    static ResourceManager& getInstance();
    void loadTexture(const std::string& name, const std::string& path);
    sf::Texture& getTexture(const std::string& name);
    void clearTextures();
};