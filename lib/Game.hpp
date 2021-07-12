/*
** EPITECH PROJECT, 2021
** physics
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Grid.hpp"

enum state_e {
    STOP,
    RUNNING
};

class Game {
    public:
        Game();
        ~Game();
        void eventHandle();
        void update(sf::Int32 dt);
        void draw();
        void display();
        void run();

        void updateGrid();

        void setState(state_e state);

    protected:
    private:
        sf::RenderWindow _window;
        sf::Event _event;
        sf::Clock *_clock;

        Grid _grid;

        state_e _state;
};

#endif /* !GAME_HPP_ */
