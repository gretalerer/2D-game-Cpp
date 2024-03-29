// move.h
#pragma once

#include <SFML/Graphics/CircleShape.hpp>

class Move {
public:
    static void movePlayer(sf::CircleShape& player, const sf::Vector2f* targetPosition, float speed);
    static void moveGhost(sf::CircleShape& ghost, const sf::Vector2f* targetPosition, float speed);
};
