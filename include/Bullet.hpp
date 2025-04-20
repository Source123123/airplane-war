#pragma once
#include "GameObject.hpp"

class Bullet : public GameObject {
public:
    bool isPlayer() const override { return false; }
    bool isEnemy() const override { return false; }
    bool isBullet() const override { return true; }
    void takeDamage(int damage) override { /* 子弹受伤逻辑 */ }
    void update(float deltaTime) override;
    int getScoreValue() const override { return 0; }

    Bullet();
    void setDirection(float x, float y);
    void move(float deltaTime);

private:
    float speed;
    float directionX;
    float directionY;
};