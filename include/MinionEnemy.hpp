#pragma once
#include "Enemy.hpp"

class MinionEnemy : public Enemy {
    float swarmMovementTimer = 0.0f;
    
public:
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) const override;
    void firePattern() override;
};