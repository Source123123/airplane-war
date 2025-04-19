#pragma once
#include "GameObject.hpp"
#include <SFML/Window/Keyboard.hpp>

class Player : public GameObject {
private:
    sf::Texture texture;
    float fireCooldown = 0.2f;
    float currentCooldown = 0.0f;
    
public:
    Player();
    void update(float deltaTime) override;
    void setTexture(const std::string& path);
    void handleInput();
    void fireBullet();
};