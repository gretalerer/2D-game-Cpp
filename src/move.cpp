// move.cpp
#include "move.h"

void Move::movePlayer(sf::CircleShape& player, sf::Vector2f& velocity, float speed) {
    velocity.x = speed; // Adjust as needed
    velocity.y = speed; // Adjust as needed

    float x = player.getPosition().x + velocity.x;
    float y = player.getPosition().y + velocity.y;
    player.setPosition(x, y);
}
