void MinionEnemy::update(float deltaTime) {
    // 实现小兵敌人的移动逻辑
    move({0.0f, 1.0f * deltaTime * 100.0f});
    GameObject::update(deltaTime);
}

void MinionEnemy::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}