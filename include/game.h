/*
 * File: game.h
 * Author: Alessandra Gorla
 * Date: November 21, 2023
 * Description: Game class header.
 */
#pragma once
#include <SFML/Graphics.hpp>

class Game {
public:
    Game();
    int run();

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
    bool ghostIsValidPosition(const sf::Vector2f& position);
    bool isCollision(sf::CircleShape& player, sf::CircleShape& ghost);
};