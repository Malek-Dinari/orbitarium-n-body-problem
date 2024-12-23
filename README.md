# Orbitarium N-Body Problem Simulation

## Project Overview

Welcome to **Orbitarium**, a C++ project simulating the **N-Body Problem**. This simulation computes the movement of celestial bodies based on gravitational forces in a 2D space. The project is built using **SFML** for rendering and **C++** for performance.

## Features

- Real-time simulation of gravity between bodies.
- Simple yet effective GUI with SFML for visualization.
- Easily extendable for adding more bodies and complex interactions.

## Current Status

- **Implemented:** Two-body gravitational interaction.
- **Next Step:** Expand to N-body simulation where each body interacts with every other body.

## Installation & Setup

1. Clone this repository:

    ```bash
    git clone https://github.com/Malek-Dinari/orbitarium-n-body-problem.git
    cd orbitarium-n-body-problem
    ```

2. Install dependencies:

    ```bash
    # You may need to install SFML if it's not already set up on your machine
    sudo apt-get install libsfml-dev
    ```

3. Build the project:

    ```bash
    mkdir build
    cd build
    cmake ..
    cmake --build .
    ```

4. Run the simulation:

    ```bash
    ./orbitarium-n-body-problem
    ```

## Future Work

- **Gravity:** Implement full N-body gravitational forces.
- **Multiple Bodies:** Simulate multiple planets and stars with realistic orbital dynamics.
- **GUI Enhancements:** Add controls to manipulate bodies and change gravitational parameters.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
