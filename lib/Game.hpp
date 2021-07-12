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

enum element_e {
    NONE,
    SAND,
    WATER
};

class Game {
    public:
        Game();
        ~Game();
        void eventHandle();
        void update(sf::Int32 dt);
        void draw();
        void display();
        void clear();
        void run();

        element_e getElementAtPosition(unsigned int x, unsigned int y);
        sf::Color getPixelColorFromElement(int value);

        bool isInRange(int x, int y);

        bool canPlaceSand(unsigned int x, unsigned int y);
        void updateSandElement(unsigned int x, unsigned int y);

        void updateNoneElement(unsigned int x, unsigned int y);

        bool canPlaceWater(unsigned int x, unsigned int y);
        void updateWaterElement(unsigned int x, unsigned int y);

        void updateElement(unsigned int x, unsigned int y);

        void fillGridAtPosition(Grid &grid, unsigned int x, unsigned int y, int value);
        void fillImageAtPosition(unsigned int x, unsigned int y, int value);
        void updateGrid();

        void setState(state_e state);

    protected:
    private:
        sf::RenderWindow _window;
        sf::Event _event;
        sf::Clock *_clock;
        sf::Image _img;
        sf::Texture _texture;
        sf::Sprite _sprite;

        Grid _grid;
        Grid _tmpGrid;

        state_e _state;

        int _width;
        int _height;
};

#endif /* !GAME_HPP_ */
