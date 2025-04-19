#pragma once
#include "Enemy.hpp"

class BossEnemy : public Enemy {
    float specialAttackTimer = 0.0f;
    
public:
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) const override;
    void firePattern() override;
};