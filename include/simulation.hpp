#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include "nbody.hpp"

class Simulation {
    private:
        std::vector<Body> bodies;
        float gravitationalConstant;


    public:
        Simulation(float g) : gravitationalConstant(g) {}

        void addBody(const Body& body);
        void update(float dt);
        void draw(sf::RenderWindow& window);
};
    

#endif
