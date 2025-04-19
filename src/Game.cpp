#include "Game.hpp"
#include "MinionEnemy.hpp"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>

Game::Game() : window(sf::VideoMode(800, 600), "Airplane War") {
    window.setFramerateLimit(60);
    resources.loadTexture("player", "resources/player.png");
    player.setTexture("player");
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
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update(float deltaTime) {
    player.update(deltaTime);
    
    for (auto& enemy : enemies) {
        enemy->update(deltaTime);
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
    auto enemy = std::make_unique<MinionEnemy>();
    enemy->setType(type);
    enemy->setPosition({static_cast<float>(rand() % 700), -50.0f});
    enemies.push_back(std::move(enemy));
}