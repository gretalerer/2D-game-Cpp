#include "bullet.h"

Bullet::Bullet(const sf::Vector2f& startPosition) : speed(500.0f), active(true) {
    shape.setRadius(5.0f);
    shape.setPosition(startPosition);
}

void Bullet::update(float deltaTime) {
    shape.move(0, -speed * deltaTime);
    if (shape.getPosition().y < 0) {
        active = false;
    }
}

void Bullet::draw(sf::RenderWindow& window) const {
    if (active) {
        window.draw(shape);
    }
}

bool Bullet::isActive() const {
    return active;
}

sf::FloatRect Bullet::getGlobalBounds() const {
    return shape.getGlobalBounds();
}


void Bullet::hit() {
    active = false; // Set 'active' to false, deactivating the bullet
}


void Bullet::setActive(bool active) {
    this->active = active;
}