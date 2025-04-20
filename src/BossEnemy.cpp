#include "BossEnemy.hpp"
#include <SFML/Graphics.hpp>

BossEnemy::BossEnemy(Game& gameRef, const sf::Texture& texture) : Enemy(texture), game(gameRef) {}

void BossEnemy::firePattern() {
    // 三向基础射击
    fireBullet(-15.0f, 400.0f);
    fireBullet(0.0f, 400.0f);
    fireBullet(15.0f, 400.0f);

    // 实现BOSS的射击模式
}

void BossEnemy::specialAbility() {
    // 实现BOSS的特殊能力
}

void BossEnemy::update(float deltaTime) {
    specialAttackTimer += deltaTime;
    
    // 阶段转换逻辑
    if (currentPhase == 1 && getHealth() < 500) {
        currentPhase = 2;
        fireInterval = 1.2f;
    }
    
    // 特殊攻击周期
    if (specialAttackTimer >= 8.0f) {
        if (currentPhase == 1) {
            // 环形弹幕
            for (int i = 0; i < 24; ++i) {
                float angle = i * 15.0f;
                fireBullet(angle, 300.0f);
            }
        } else {
            // 召唤小怪
            for (int i = 0; i < 3; ++i) {
                game.spawnMinionAt(getPosition().x + i*50, getPosition().y);
            }
        }
        specialAttackTimer = 0.0f;
    }

    // 实现BOSS特有逻辑
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