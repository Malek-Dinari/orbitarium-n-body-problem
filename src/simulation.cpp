#include "simulation.hpp"

void Simulation::addBody(const Body& body) {
    bodies.push_back(body);
}

void Simulation::update(float dt) {
    for (size_t i = 0; i < bodies.size(); ++i) {
        sf::Vector2f totalForce(0.f, 0.f);

        for (size_t j = 0; j < bodies.size(); ++j) {
            if (i != j) {
                totalForce += bodies[i].calculateForce(bodies[j]);
            }
        }
        bodies[i].applyForce(totalForce);
    }

    for (auto& body : bodies) {
        body.update(dt);
    }
}

void Simulation::draw(sf::RenderWindow& window) {
    for (auto& body : bodies) {
        body.draw(window);
    }
}
