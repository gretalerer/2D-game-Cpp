// move.h
#pragma once

#include <SFML/Graphics/CircleShape.hpp>

class Move {
public:
    static void movePlayer(sf::CircleShape& player, sf::Vector2f& velocity, float speed);
};
