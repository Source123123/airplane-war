#include "Enemy.hpp"
#include "ResourceManager.hpp"

void Enemy::update(float deltaTime) {
    sprite.move(velocity * deltaTime);
    fireTimer += deltaTime;
    
    if(fireTimer >= fireInterval) {
        firePattern();
        fireTimer = 0;
    }
}

int Enemy::getScoreValue() const {
    return scoreValue;
}

void Enemy::setType(Type newType) {
    switch(newType) {
        case Type::Grunt:
            setTexture("enemy_grunt");
            velocity = {0, 150};
            break;
        case Type::Boss:
            setTexture("enemy_boss");
            velocity = {0, 80};
            break;
    }
}