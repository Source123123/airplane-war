#include "Player.hpp"
#include "ResourceManager.hpp"

Player::Player() : GameObject(ResourceManager::getInstance().getTexture("player")) {
    setPosition({400, 500});
}

void Player::takeDamage(int damage) {
    // 实现玩家受伤逻辑
}

void Player::update(float deltaTime) {
    handleInput();
    currentCooldown -= deltaTime;
}

void Player::handleInput() {
    float speed = 300.0f;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) velocity.x = -speed;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) velocity.x = speed;
    else velocity.x = 0;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && currentCooldown <= 0) {
        fireBullet();
        currentCooldown = fireCooldown;
    }
}