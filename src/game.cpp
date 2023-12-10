/*
 * File: game.cpp
 * Author: Alessandra Gorla
 * Date: November 21, 2023
 * Description: Game class to deal with initialization and controller of 2D my game application.
 */
#include "game.h"
#include "move.h"

const float Game::SCENE_WIDTH = 800.0f;
const float Game::SCENE_HEIGHT = 600.0f;
const float Game::PLAYER_START_X = 400.0f;
const float Game::PLAYER_START_Y = 300.0f;
const float Game::RADIUS = 20.0f;

Game::Game() {
    initWindow();
    initBackground();
    initPlayer();
}
/**
 * Window initializer.
 */
int Game::initWindow() {
    window.create(sf::VideoMode(SCENE_WIDTH, SCENE_HEIGHT), "My 2D game");
    window.setFramerateLimit(120);
    return 0;
}
/**
 * Background initializer.
 */
int Game::initBackground() {
    if (!backgroundTexture.loadFromFile("resources/background.png")) {
        return 1;
    }
    backgroundTexture.setRepeated(true);
    background.setTexture(backgroundTexture);
    background.setTextureRect(sf::IntRect(0, 0, SCENE_WIDTH, SCENE_HEIGHT));
    return 0;
}

/**
 * Player (e.g. PacMan) initializer
 * @return 0 if successfully initialized, 1 otherwise
 */
int Game::initPlayer() {
    player.setRadius(RADIUS);
    player.setOrigin(RADIUS, RADIUS);
    player.setPosition(PLAYER_START_X, PLAYER_START_Y);
    if (!playerTexture.loadFromFile("resources/pacman.png")) {
        return 1;
    }
    player.setTexture(&playerTexture);
    return 0;
}

/**
 * Dealing with events on window.
 */
void Game::processInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
        }
    }
}

/**
 * Function to update the position of the player
 */
void Game::update() {
    sf::Vector2f targetPosition(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        targetPosition = sf::Vector2f(-1.f, 0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        targetPosition = sf::Vector2f(1.f, 0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        targetPosition = sf::Vector2f(0.f, +1.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        targetPosition = sf::Vector2f(0.f, -1.f);
    }

    sf::Vector2f newPosition = player.getPosition() + targetPosition;
    if (newPosition.x - RADIUS >= 0 && newPosition.x + RADIUS <= SCENE_WIDTH &&
        newPosition.y - RADIUS >= 0 && newPosition.y + RADIUS <= SCENE_HEIGHT) {
        Move::movePlayer(player, &targetPosition, 1.0f);
    }
}

/**
 * Render elements in the window
 */
void Game::render() {
    window.clear(sf::Color::White);
    window.draw(background);
    window.draw(player);
    window.display();
}
/**
 * Main function to deal with events, update the player and render the updated scene on the window.
 */
int Game::run() {
    while (window.isOpen()) {
        processInput();
        update();
        render();
    }
    return 0;
}

//hola soy greta