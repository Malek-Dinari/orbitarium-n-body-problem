// orbitarium-n-body-problem: main.cpp : Defines the entry point for the application.
//

#include "orbitarium-n-body-problem.hpp"

using namespace std;

#include <SFML/Graphics.hpp>
#include <simulation.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Orbitarium - N-Body Problem");
    Simulation simulation(0.1f); // Gravitational constant

    // Create bodies
    simulation.addBody(Body(400.f, 400.f, 0.f, 0.f, 10000.f, 20.f, sf::Color::Yellow)); // Sun
    simulation.addBody(Body(600.f, 400.f, 0.f, -50.f, 10.f, 5.f, sf::Color::Blue));    // Planet

    sf::Clock clock;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        float dt = clock.restart().asSeconds();
        simulation.update(dt);

        window.clear(sf::Color::Black);
        simulation.draw(window);
        window.display();
    }

    return 0;
}

