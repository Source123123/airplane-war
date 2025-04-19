#pragma once
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Enemy.hpp"
#include "ResourceManager.hpp"

class Game {
private:
    sf::RenderWindow window;
    Player player;
    ResourceManager resources;
    std::vector<std::unique_ptr<Enemy>> enemies;
    
    void handleInput();
    void update(float deltaTime);
    void render();
    
public:
    Game();
    void run();
    void spawnEnemy(Enemy::Type type);
};