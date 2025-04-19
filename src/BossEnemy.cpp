#include "BossEnemy.hpp"
#include <SFML/Graphics.hpp>

void BossEnemy::firePattern() {
    // 实现BOSS的射击模式
}

void BossEnemy::specialAbility() {
    // 实现BOSS的特殊能力
}

void BossEnemy::update(float deltaTime) {
    // 实现BOSS特有逻辑
    specialAttackTimer += deltaTime;
    if(specialAttackTimer > 5.0f) {
        // 释放特殊攻击
        specialAttackTimer = 0.0f;
    }
    GameObject::update(deltaTime);
}

void BossEnemy::draw(sf::RenderWindow& window) const {
    // BOSS特有绘制逻辑
    window.draw(sprite);
}

void BossEnemy::firePattern() {
    // 实现BOSS弹幕模式
}