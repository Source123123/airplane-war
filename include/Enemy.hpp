#pragma once
#include "GameObject.hpp"

class Enemy : public GameObject {
protected:
    int scoreValue = 100;
    float fireInterval = 2.0f;
    float fireTimer = 0.0f;

public:
    enum class Type { Grunt, Boss };
    
    virtual void update(float deltaTime) override;
    virtual ~Enemy() = default;
    virtual void firePattern() = 0;
    virtual void specialAbility() = 0;
    int getScoreValue() const;
    void setType(Type newType);
};