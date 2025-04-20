#pragma once
#include <SFML/Graphics.hpp>
#include <optional>
#include "Player.hpp"
#include "Enemy.hpp"
#include "ResourceManager.hpp"
#include "CollisionGrid.hpp"
#include "MinionEnemy.hpp"
#include "Bullet.hpp"

class Game {
    CollisionGrid collisionGrid;
    void handleCollision(GameObject& a, GameObject& b);
private:
    sf::RenderWindow window;
    Player player;
    ResourceManager resources;
    std::vector<std::unique_ptr<Enemy>> enemies;
    std::vector<std::unique_ptr<MinionEnemy>> enemyPool;
    std::vector<std::unique_ptr<Bullet>> bulletPool;
    int score;

public:
    void initObjectPools();
    void handleInput();
    void update(float deltaTime);
    void render();
    
public:
    Game();
    void run();
    void spawnEnemy(Enemy::Type type);
    void spawnMinionAt(float x, float y);
};