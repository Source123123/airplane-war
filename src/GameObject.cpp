#include "GameObject.hpp"
#include <SFML/Graphics.hpp>

sf::Vector2f GameObject::getPosition() const {
    return sprite.getPosition();
}

// 其他GameObject基类方法实现
void GameObject::setPosition(const sf::Vector2f& pos) {
    sprite.setPosition(pos);
}

void GameObject::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}