#ifndef NBODY_H
#define NBODY_H

#include <SFML/Graphics.hpp>
#include <cmath>

constexpr float gravitationalConstant = 6.67430e-11f;

class Body {
private:
    sf::CircleShape shape;
    sf::Vector2f position;
    sf::Vector2f velocity;
    float mass;


public:
    Body(float x, float y, float vx, float vy, float m, float radius, sf::Color color);

    void update(float dt);
    void applyForce(const sf::Vector2f& force);
    sf::Vector2f calculateForce(const Body& other) const;

    const sf::Vector2f& getPosition() const { return position; }
    float getMass() const { return mass; }
    void draw(sf::RenderWindow& window);
};

#endif
