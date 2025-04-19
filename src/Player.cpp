#include "Player.hpp"
#include "ResourceManager.hpp"

Player::Player() {
    setTexture("player");
    setPosition({400, 500});
}

void Player::update(float deltaTime) {
    handleInput();
    currentCooldown -= deltaTime;
}

void Player::handleInput() {
    float speed = 300.0f;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) velocity.x = -speed;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) velocity.x = speed;
    else velocity.x = 0;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && currentCooldown <= 0) {
        fireBullet();
        currentCooldown = fireCooldown;
    }
}

void Player::setTexture(const std::string& path) {
    texture = ResourceManager::getInstance().getTexture(path);
    sprite.setTexture(texture);
}