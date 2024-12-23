#include <nbody.hpp>


Body::Body(float x, float y, float vx, float vy, float m, float radius, sf::Color color)
    : position(x, y), velocity(vx, vy), mass(m) {
    shape.setRadius(radius);
    shape.setFillColor(color);
    shape.setOrigin(sf::Vector2f(radius, radius));
    shape.setPosition(position);
}

void Body::update(float dt) {
    position += velocity * dt;
    shape.setPosition(position);
}

void Body::applyForce(const sf::Vector2f& force) {
    velocity += force / mass;
}

sf::Vector2f Body::calculateForce(const Body& other) const {
    sf::Vector2f direction = other.getPosition() - position;
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (distance == 0) return { 0, 0 }; // Avoid division by zero

    direction /= distance; // Normalize
    float forceMagnitude = (gravitationalConstant * mass * other.getMass()) / (distance * distance);
    return forceMagnitude * direction;
}

void Body::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
