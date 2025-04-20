#pragma once
#include <vector>
#include <functional>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

class CollisionGrid {
    int cellSize;
    std::vector<std::vector<std::vector<GameObject*>>> grid;

public:
    CollisionGrid(int size = 100);
    void clear();
    void insert(GameObject& obj);
    void checkCollisions(std::function<void(GameObject&, GameObject&)> handler);
};