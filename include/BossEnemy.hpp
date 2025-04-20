#pragma once
#include "Enemy.hpp"
#include "Game.hpp"

class BossEnemy : public Enemy {
    Game& game;
    float specialAttackTimer = 0.0f;
    int currentPhase = 1;
    
public:
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) const override;
    void firePattern() override;
    void specialAbility() override;
    int getHealth() const;
public:
    BossEnemy(Game& gameRef, const sf::Texture& texture);
};