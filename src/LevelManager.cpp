#include "LevelManager.hpp"
#include "Game.hpp"
#include <cmath>

LevelManager::LevelManager(Game& game) : game(game) {
    currentWave = 0;
    spawnCooldown = 3.0f;
}

void LevelManager::update(float deltaTime) {
    // 波次控制逻辑
    if (currentWave < 5) {
        handleNormalWave(deltaTime);
    } else {
        handleBossWave(deltaTime);
    }
}

void LevelManager::handleNormalWave(float deltaTime) {
    spawnCooldown -= deltaTime;
    
    if (spawnCooldown <= 0) {
        // 正弦波敌人生成模式
        const int enemiesToSpawn = 3 + currentWave * 2;
        for (int i = 0; i < enemiesToSpawn; ++i) {
            const float angle = (i * 3.1416f * 2) / enemiesToSpawn;
            const float offsetX = std::sin(angle) * 200.0f;
            game.spawnEnemyAt(400 + offsetX, -50.0f);
        }
        
        spawnCooldown = 4.0f - currentWave * 0.3f;
        currentWave++;
    }
}

void LevelManager::handleBossWave(float deltaTime) {
    if (!bossSpawned) {
        game.spawnBoss();
        bossSpawned = true;
    }
}