#pragma once
#include "GameObject.hpp"

class Enemy : public GameObject {
public:
    explicit Enemy(const sf::Texture& texture) : GameObject(texture) {}
    bool isPlayer() const override { return false; }
    bool isEnemy() const override { return true; }
    bool isBullet() const override { return false; }
    void takeDamage(int damage) override { /* 敌人受伤逻辑 */ }
    void setTexture(const sf::Texture& texture) override;
protected:
    int scoreValue = 100;
    float fireInterval = 2.0f;
    float fireTimer = 0.0f;

public:
    enum class Type { Grunt, Boss };
    
    virtual void update(float deltaTime) override;
    virtual ~Enemy() = default;
    virtual void firePattern() = 0;
    virtual void specialAbility() = 0;
    virtual void fireBullet(float x, float y) = 0;
    int getScoreValue() const override;
    void setType(Type newType);

public:

};