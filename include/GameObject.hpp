#pragma once
#include <SFML/Graphics.hpp>

class GameObject {
protected:
    sf::Sprite sprite;
    sf::Vector2f velocity;
    bool isActive = true;

public:
    virtual void update(float deltaTime) = 0;
    virtual void draw(sf::RenderWindow& window);
    void setPosition(const sf::Vector2f& pos);
    sf::FloatRect getGlobalBounds() const;
    bool checkCollision(const GameObject& other) const;
    void setActive(bool active);
};