#include "Game.hpp"
#include "MinionEnemy.hpp"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>

Game::Game() : window(sf::VideoMode({800, 600}), "Airplane War"), score(0) {
    window.setFramerateLimit(60);
    resources.loadTexture("player", "resources/player.png");
    player.setTexture("player");
    
    // 初始化对象池
    initObjectPools();
}

void Game::initObjectPools() {
    // 预生成20个敌人实例
    for (int i = 0; i < 20; ++i) {
        auto enemy = std::make_unique<MinionEnemy>(resources.getTexture("minion"));
        enemy->setActive(false);
        enemyPool.push_back(std::move(enemy));
    }
    
    // 预生成50发子弹
    for (int i = 0; i < 50; ++i) {
        auto bullet = std::make_unique<Bullet>();
        bullet->setActive(false);
        bulletPool.push_back(std::move(bullet));
    }
}

void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        handleInput();
        update(deltaTime);
        render();
    }
}

void Game::handleInput() {
    while (auto event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
    }
}

void Game::update(float deltaTime) {
    // 更新碰撞网格
    collisionGrid.clear();
    collisionGrid.insert(player);
    for (auto& enemy : enemies) {
        collisionGrid.insert(*enemy);
    }

    player.update(deltaTime);
    
    // 分网格处理碰撞
    collisionGrid.checkCollisions([this](GameObject& a, GameObject& b) {
        handleCollision(a, b);
    });

    for (auto& enemy : enemies) {
        enemy->update(deltaTime);
    }
}

void Game::handleCollision(GameObject& a, GameObject& b) {
    if (a.isPlayer() && b.isEnemy()) {
        player.takeDamage(10);
        b.setActive(false);
    }
    else if (a.isBullet() && b.isEnemy()) {
        this->score += b.getScoreValue();
        a.setActive(false);
        b.setActive(false);
    }
}

void Game::render() {
    window.clear();
    player.draw(window);
    
    for (auto& enemy : enemies) {
        enemy->draw(window);
    }
    
    window.display();
}

void Game::spawnEnemy(Enemy::Type type) {
    auto enemy = std::make_unique<MinionEnemy>(resources.getTexture("minion"));
    enemy->setType(type);
    enemy->setPosition({static_cast<float>(rand() % 700), -50.0f});
    enemies.push_back(std::move(enemy));
}

void Game::spawnMinionAt(float x, float y) {
    auto minion = std::make_unique<MinionEnemy>(resources.getTexture("minion"));
    minion->setPosition(sf::Vector2f(x, y));
    enemies.push_back(std::move(minion));
}