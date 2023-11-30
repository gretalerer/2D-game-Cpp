// move.cpp
#include "move.h"
#include <cmath>

void Move::movePlayer(sf::CircleShape& player, const sf::Vector2f& targetPosition, float speed) {
    sf::Vector2f currentPosition = player.getPosition();
    sf::Vector2f direction = targetPosition - currentPosition;

    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length > 0) {
        direction /= length;
    }

    sf::Vector2f velocity = direction * speed;
    player.move(velocity);
}
