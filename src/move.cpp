// move.cpp
#include "move.h"
#include <cmath>

void Move::movePlayer(sf::CircleShape& player, const sf::Vector2f* targetPosition, float speed) {
    // Check if the pointer is valid before dereferencing
    if (targetPosition) {
      // Dereference the pointer and update the target position
      sf::Vector2f movement = (*targetPosition) * speed;
      player.move(movement);
    }
}


//hola soy greta