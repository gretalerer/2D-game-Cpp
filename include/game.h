/*
 * File: game.h
 * Author: Alessandra Gorla
 * Date: November 21, 2023
 * Description: Game class header.
 */
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>  
#include "bullet.h"

class Game {
    friend class GameTest;
public:
    Game();
    int run();
    sf::Vector2f getPlayerStartPosition() const {
        return sf::Vector2f(PLAYER_START_X, PLAYER_START_Y);
    }
    float getSceneWidth() const { return SCENE_WIDTH; }
    float getSceneHeight() const { return SCENE_HEIGHT; }

     bool testIsCollision(sf::CircleShape& player, sf::CircleShape& ghost) {
        return isCollision(player, ghost);
    }

    bool testGhostIsValidPosition(const sf::Vector2f& position) {
        return ghostIsValidPosition(position);
    }

private:
    sf::RenderWindow window;
    sf::Sprite background;
    sf::Texture backgroundTexture;
    sf::Texture playerTexture;
    sf::Texture ghostTexture;
    sf::Texture explosionTexture;
    sf::CircleShape player;
    sf::CircleShape ghost;
    sf::Clock ghostMoveClock;
    sf::Clock explosionTimer;
    std::vector<sf::CircleShape> ghosts;  
    sf::Clock ghostSpawnClock;
    std::vector<sf::Clock> ghostMoveClocks;
    std::vector<Bullet> bullets;


    static const float SCENE_WIDTH;
    static const float SCENE_HEIGHT;
    static const float PLAYER_START_X;
    static const float PLAYER_START_Y;
    static float GHOST_START_X;
    static float GHOST_START_Y;
    static const float RADIUS;

    int initWindow();
    int initBackground();
    int initExplosionTexture();
    int initPlayer();
    int initGhost();
    void processInput();
    void update();
    void render();
    bool isCollision(sf::CircleShape& player, sf::CircleShape& ghost);
    bool ghostIsValidPosition(const sf::Vector2f& position);
    void generateRandomGhost();
    void shootBullet();
};