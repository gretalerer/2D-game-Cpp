#include <gtest/gtest.h>
#include "game.h"

class GameTest : public ::testing::Test {
protected:
    Game game;
    
    void SetUp() override {
        // Initialize game 
    }
};

TEST_F(GameTest, CollisionDetection) {
    sf::CircleShape player(20.0f), ghost(20.0f);
    player.setPosition(100, 100);
    ghost.setPosition(100, 100);  // Same position as player, should collide

    EXPECT_TRUE(game.testIsCollision(player, ghost));
}


// Ghost movement within boundaries
TEST_F(GameTest, GhostMovementWithinBoundaries) {
    sf::Vector2f newPosition(400.0f, 300.0f);  // Assuming within game boundaries
    EXPECT_TRUE(game.testGhostIsValidPosition(newPosition));
}

// Player movement within boundaries
TEST_F(GameTest, PlayerMovementWithinBoundaries) {
    sf::CircleShape player(20.0f);
    sf::Vector2f startPos = game.getPlayerStartPosition();
    player.setPosition(startPos);

    // Simulate movement
    sf::Vector2f movement(50.0f, 0.0f); // Move right
    player.move(movement);

    // Check if new position is within boundaries
    bool withinBoundaries = player.getPosition().x <= game.getSceneWidth() &&
                            player.getPosition().y <= game.getSceneHeight();
    EXPECT_TRUE(withinBoundaries);
}

// Test will check if a bullet is correctly created with the expected initial properties
TEST(BulletTest, BulletCreation) {
    sf::Vector2f startPosition(100.0f, 100.0f);
    Bullet bullet(startPosition);
    EXPECT_TRUE(bullet.isActive());
    EXPECT_NEAR(bullet.getGlobalBounds().left, startPosition.x, 0.1f);
}



