#pragma once
#include <SFML/Graphics.hpp>

class GameObject {
protected:
    sf::Sprite sprite;
    sf::Vector2f velocity;
    bool isActive = true;

    // 新增虚函数声明
public:
    virtual bool isPlayer() const = 0;
    virtual bool isEnemy() const = 0;
    virtual bool isBullet() const = 0;
    virtual void takeDamage(int damage) = 0;
    virtual int getScoreValue() const = 0;

public:
    virtual void setTexture(const sf::Texture& texture);
    virtual void update(float deltaTime) {}
    virtual void draw(sf::RenderWindow& window) const;
    void setPosition(const sf::Vector2f& pos);
    sf::Vector2f getPosition() const;
    sf::FloatRect getGlobalBounds() const;
    bool checkCollision(const GameObject& other) const;
    void setActive(bool active);

public:
    GameObject(const sf::Texture& texture) : sprite(texture) {}
};