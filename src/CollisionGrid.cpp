#include "CollisionGrid.hpp"
#include "GameObject.hpp"

CollisionGrid::CollisionGrid(int size) : cellSize(size) {
    grid.resize((800/size + 1), std::vector<std::vector<GameObject*>>((600/size + 1)));
}

void CollisionGrid::clear() {
    for (auto& column : grid) {
        for (auto& cell : column) {
            cell.clear();
        }
    }
}

void CollisionGrid::insert(GameObject& obj) {
    sf::FloatRect bounds = obj.getGlobalBounds();
    sf::Vector2f pos = obj.getPosition();
    float left_pos = pos.x;
    float top_pos = pos.y;
    float width_val = bounds.getSize().x;
    float height_val = bounds.getSize().y;
    
    int left = static_cast<int>(left_pos / cellSize);
    int right = static_cast<int>((left_pos + width_val) / cellSize);
    int top = static_cast<int>(top_pos / cellSize);
    int bottom = static_cast<int>((top_pos + height_val) / cellSize);

    for (int x = left; x <= right; ++x) {
        for (int y = top; y <= bottom; ++y) {
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
                grid[x][y].push_back(&obj);
            }
        }
    }
}

void CollisionGrid::checkCollisions(std::function<void(GameObject&, GameObject&)> handler) {
    for (auto& column : grid) {
        for (auto& cell : column) {
            for (size_t i = 0; i < cell.size(); ++i) {
                for (size_t j = i + 1; j < cell.size(); ++j) {
                    if (cell[i]->checkCollision(*cell[j])) {
                        handler(*cell[i], *cell[j]);
                    }
                }
            }
        }
    }
}