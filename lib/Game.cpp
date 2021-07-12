/*
** EPITECH PROJECT, 2021
** physics
** File description:
** Game
*/

#include "Game.hpp"

Game::Game() : _clock(nullptr), _state(RUNNING), _width(800), _height(600)
{
    _window.create((sf::VideoMode){800, 600, 32}, "Physics", sf::Style::Default);
    sf::Uint8* pixels = new sf::Uint8[_width * _height * 4];
    _img.create(800, 600, pixels);
    _texture.create(1, 1);
    _texture.loadFromImage(_img);
}

Game::~Game()
{

}

void Game::eventHandle()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == _event.Closed) { _window.close(); setState(STOP);}
    }
}

element_e Game::getElementAtPosition(unsigned int x, unsigned int y)
{
    return ((element_e)_grid.getValueAtPosition(x, y));
}

sf::Color Game::getPixelColorFromElement(int value)
{
    switch (value) {
        case SAND :
            return ((sf::Color){250, 230, 179, 255});
        case WATER :
            return ((sf::Color){7, 98, 155, 255});
        default:
            return ((sf::Color){0, 0, 0, 255});
    }
}

void Game::fillImageAtPosition(unsigned int x, unsigned int y, int value)
{
    _img.setPixel(x, y, getPixelColorFromElement(value));
}

bool Game::isInRange(int x, int y)
{
    if (x < 0 || x > _width) return (false);
    if (y < 0 || y > _height) return (false);
    return (true);
}

void Game::updateNoneElement(unsigned int x, unsigned int y)
{
    if (isInRange(x, y))
        fillGridAtPosition(_tmpGrid, x, y, NONE);
}

bool Game::canPlaceSand(unsigned int x, unsigned int y)
{
    if (_grid.getGrid().at(y).at(x) != NONE && _grid.getGrid().at(y).at(x) != SAND) return (false);
    return (true);
}

void Game::updateSandElement(unsigned int x, unsigned int y)
{
    if (isInRange(x, y + 1) && canPlaceSand(x, y + 1))
        fillGridAtPosition(_tmpGrid, x, y + 1, SAND);
    else if (isInRange(x + 1, y + 1) && canPlaceSand(x + 1, y + 1))
        fillGridAtPosition(_tmpGrid, x + 1, y + 1, SAND);
    else if (isInRange(x - 1, y + 1) && canPlaceSand(x - 1, y + 1))
        fillGridAtPosition(_tmpGrid, x - 1, y + 1, SAND);
    else
        fillGridAtPosition(_tmpGrid, x, y, SAND);
}

bool Game::canPlaceWater(unsigned int x, unsigned int y)
{
    if (_grid.getGrid().at(y).at(x) != NONE) return (false);
    return (true);
}

void Game::updateWaterElement(unsigned int x, unsigned int y)
{
    if (isInRange(x, y + 1) && canPlaceWater(x, y + 1))
        fillGridAtPosition(_tmpGrid, x, y + 1, WATER);
    else if (isInRange(x + 1, y + 1) && canPlaceWater(x + 1, y + 1))
        fillGridAtPosition(_tmpGrid, x + 1, y + 1, WATER);
    else if (isInRange(x - 1, y + 1) && canPlaceWater(x - 1, y + 1))
        fillGridAtPosition(_tmpGrid, x - 1, y + 1, WATER);
    else
        fillGridAtPosition(_tmpGrid, x, y, WATER);
}

void Game::updateElement(unsigned int x, unsigned int y)
{
    switch (getElementAtPosition(x, y)) {
        case NONE: updateNoneElement(x, y);
            return;
        case SAND: updateSandElement(x, y);
            return;
        case WATER: updateWaterElement(x, y);
            return;
        default: return;
    }
}

void Game::fillGridAtPosition(Grid &grid, unsigned int x, unsigned int y, int value)
{
    grid.setValueAtPosition(x, y, value);
}

void Game::updateGrid()
{
    for (int y = 0; y < _height; y++) {
        for (int x = 0; x < _width; x++) {
            updateElement(x, y);
        }
    }
}

void Game::update(sf::Int32 dt)
{
    updateGrid();
}

void Game::draw()
{
    _texture.update(_img);
    _sprite.setTexture(_texture, true);
    _window.draw(_sprite, sf::RenderStates::Default);
    
}

void Game::display()
{
    _window.display();
}

void Game::clear()
{
    _window.clear(sf::Color::White);
}

void Game::run()
{
    if (!_clock) { _clock = new sf::Clock(); }

    while (_state == RUNNING) {
        clear();
        eventHandle();
        update(_clock->restart().asMilliseconds());
        draw();
        display();
    }
}

void Game::setState(state_e state)
{
    _state = state;
}