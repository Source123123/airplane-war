#pragma once
#include "GameObject.hpp"
#include <SFML/Window/Keyboard.hpp>

class Player : public GameObject {
public:
    bool isPlayer() const override { return true; }
    bool isEnemy() const override { return false; }
    bool isBullet() const override { return false; }
    void takeDamage(int damage) override;
    int getScoreValue() const override { return 0; }

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