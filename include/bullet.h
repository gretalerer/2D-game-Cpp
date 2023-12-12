#pragma once
#include <SFML/Graphics.hpp>

class Bullet {
public:
    Bullet(const sf::Vector2f& startPosition);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window) const;
    bool isActive() const;
    sf::FloatRect getGlobalBounds() const;
    void hit();
    void setActive(bool active);
    
private:
    sf::CircleShape shape;
    float speed;
    bool active;
};
