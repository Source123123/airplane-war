#include "MinionEnemy.hpp"
#include <SFML/Graphics.hpp>

MinionEnemy::MinionEnemy(const sf::Texture& texture) : Enemy(texture) {}

void MinionEnemy::update(float deltaTime) {
    // 实现小兵敌人的移动逻辑
    setPosition(sf::Vector2f(getPosition().x, getPosition().y + 1.0f * deltaTime * 100.0f));
    GameObject::update(deltaTime);
}

void MinionEnemy::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

void MinionEnemy::fireBullet(float x, float y) {
    // 实现小兵敌人的子弹发射逻辑
}

void MinionEnemy::specialAbility() {
    // 实现小兵敌人的特殊能力
    firePattern();
}

void MinionEnemy::firePattern() {
    // 实现小兵敌人的射击模式
    // 简单的直线射击
    fireBullet(0.0f, 300.0f);
}