#pragma once
#include "Enemy.hpp"
#include <SFML/Graphics.hpp>

class MinionEnemy : public Enemy {
public:
    MinionEnemy(const sf::Texture& texture);
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) const override;
    void fireBullet(float x, float y) override;
    void specialAbility() override;
    void firePattern() override;

private:
    float swarmMovementTimer = 0.0f;
};