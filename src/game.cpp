/*
 * File: game.cpp
 * Author: Alessandra Gorla
 * Date: November 21, 2023
 * Description: Game class to deal with initialization and controller of 2D my game application.
 */
#include "game.h"
#include "move.h"
#include <cstdlib>
#include <cmath>


const float Game::SCENE_WIDTH = 800.0f;
const float Game::SCENE_HEIGHT = 600.0f;
const float Game::PLAYER_START_X = 400.0f;
const float Game::PLAYER_START_Y = 300.0f;
const float Game::RADIUS = 20.0f;
float Game::GHOST_START_X;
float Game::GHOST_START_Y;

Game::Game() : ghostMoveClock() {
    initWindow();
    initBackground();
    initPlayer();
    initExplosionTexture();
    initGhost();
    explosionTimer.restart();
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

int Game::initExplosionTexture() {
    if (!explosionTexture.loadFromFile("resources/pacman-explosion.png")) {
        return 1; // Texture loading failed
    }
    return 0; // Texture loading succeeded
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

int Game::initGhost() {
        GHOST_START_X = (rand() % 800 + 1);
        GHOST_START_Y = (rand() % 600 + 1);

        ghost.setRadius(RADIUS);
        ghost.setOrigin(RADIUS, RADIUS);
        ghost.setPosition(GHOST_START_X, GHOST_START_Y);

        if (!ghostTexture.loadFromFile("resources/ghost.png")) {
            return 1;
        }

        ghost.setTexture(&ghostTexture);

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

bool wasColliding = false;

void Game::update() {
    static sf::Clock deltaClock;
    float deltaTime = deltaClock.restart().asSeconds();

    // Player movement handling
    sf::Vector2f targetPosition(0.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        targetPosition = sf::Vector2f(-1.f, 0.f);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        targetPosition = sf::Vector2f(1.f, 0.f);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        targetPosition = sf::Vector2f(0.f, 1.f);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        targetPosition = sf::Vector2f(0.f, -1.f);
    }

    sf::Vector2f newPositionPlayer = player.getPosition() + targetPosition;
    if (newPositionPlayer.x - RADIUS >= 0 && newPositionPlayer.x + RADIUS <= SCENE_WIDTH &&
        newPositionPlayer.y - RADIUS >= 0 && newPositionPlayer.y + RADIUS <= SCENE_HEIGHT) {
        Move::movePlayer(player, &targetPosition, 1.0f);
    }

    // Handle shooting
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        shootBullet();
    }

    // Update bullets
    for (auto& bullet : bullets) {
        bullet.update(deltaTime);
    }

    // Remove inactive bullets
    bullets.erase(std::remove_if(bullets.begin(), bullets.end(), 
                 [](const Bullet& b) { return !b.isActive(); }), bullets.end());

    // Ghost spawning
    if (ghostSpawnClock.getElapsedTime().asSeconds() >= 1.0) {
        generateRandomGhost();
        ghostSpawnClock.restart();
    }

    // Update and collision check for each ghost
    for (auto& ghost : ghosts) {
        if (ghostMoveClock.getElapsedTime().asSeconds() >= 0.5) {
            float x_direction = (rand() % 3 - 1);  
            float y_direction = (rand() % 3 - 1);  
            float speed = static_cast<float>(rand() % 5 + 1);

            sf::Vector2f target_pos_ghost = sf::Vector2f(x_direction * speed, y_direction * speed);
            sf::Vector2f potentialNewPosition = ghost.getPosition() + target_pos_ghost;

            if (ghostIsValidPosition(potentialNewPosition)) {
                Move::moveGhost(ghost, &target_pos_ghost, 1.0f);
                ghostMoveClock.restart();
            }
        }

        // Check bullet collisions with ghosts
        for (auto& bullet : bullets) {
            for (auto& ghost : ghosts) {
                if (bullet.isActive() && bullet.getGlobalBounds().intersects(ghost.getGlobalBounds())) {
                    bullet.setActive(false);  // Deactivate the bullet
                    ghost.setTexture(&explosionTexture); // Change ghost's texture to explosion
                }
            }
        }
    }

    // Collision handling between player and ghosts
    bool collisionOccurred = false;
    for (auto& ghost : ghosts) {
        if (isCollision(player, ghost)) {
            collisionOccurred = true;
            break; // Assuming one collision is enough to trigger the effect
        }
    }

    // Handling collision effect
    if (collisionOccurred) {
        player.setTexture(&explosionTexture);
        wasColliding = true;  // Update the flag
    } else if (wasColliding) {
        // Change the texture back immediately when no longer colliding
        player.setTexture(&playerTexture);
        wasColliding = false;  // Update the flag
    }
}


    

void Game::generateRandomGhost() {
    sf::CircleShape newGhost(RADIUS);
    newGhost.setOrigin(RADIUS, RADIUS);
    newGhost.setPosition(rand() % (int)SCENE_WIDTH, rand() % (int)SCENE_HEIGHT);
    newGhost.setTexture(&ghostTexture);
    ghosts.push_back(newGhost);

    ghostMoveClocks.push_back(sf::Clock());  // Add a new clock for the new ghost
}



bool Game::ghostIsValidPosition(const sf::Vector2f &position) {
    // Checking if the entire ghost (considering radius) is within the scene
    return (position.x - RADIUS >= 0 && position.x + RADIUS <= SCENE_WIDTH &&
            position.y - RADIUS >= 0 && position.y + RADIUS <= SCENE_HEIGHT);
}


bool Game::isCollision(sf::CircleShape& player, sf::CircleShape& ghost){
    sf::Vector2f pos_ghost = ghost.getPosition();
    sf::Vector2f pos_player = player.getPosition();
    float distance = sqrt(pow(pos_ghost.x - pos_player.x, 2) + pow(pos_ghost.y - pos_player.y, 2));

    if (distance < RADIUS * 2) {
        player.setTexture(&explosionTexture);

        explosionTimer.restart();
        return true;
    }
    return false;

}

void Game::shootBullet() {
    sf::Vector2f startPosition = player.getPosition(); 
    bullets.emplace_back(startPosition);
}


/**
 * Render elements in the window
 */
void Game::render() {
    window.clear(sf::Color::White);
    window.draw(background);
    window.draw(player);
    for (const auto& ghost : ghosts) {  // Draw all ghosts
        window.draw(ghost);
    }
    for (const auto& bullet : bullets) {
        bullet.draw(window);
    }
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
