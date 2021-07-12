/*
** EPITECH PROJECT, 2021
** physics
** File description:
** Game
*/

#include "Game.hpp"

Game::Game() : _clock(nullptr), _state(RUNNING)
{
    _window.create((sf::VideoMode){800, 600, 32}, "Physics", sf::Style::Default);
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

void Game::updateGrid()
{
    
}

void Game::update(sf::Int32 dt)
{

}

void Game::draw()
{

}

void Game::display()
{
    _window.display();
}

void Game::run()
{
    if (!_clock) { _clock = new sf::Clock(); }

    while (_state == RUNNING) {
        eventHandle();
        update(_clock->getElapsedTime().asMilliseconds());
        draw();
    }
}

void Game::setState(state_e state)
{
    _state = state;
}