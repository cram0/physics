#include "Grid.hpp"

Grid::Grid()
{
    initializeGrid(800, 600);
}

Grid::Grid(unsigned int column, unsigned int line)
{
    initializeGrid(column, line);
}

Grid::~Grid()
{

}

std::vector<std::vector<int>> Grid::getGrid() const
{
    return (_grid);
}

void Grid::initializeGrid(unsigned int column, unsigned int line)
{
    for (unsigned int y = 0; y < line; y++) {
        _grid.emplace_back(std::vector<int>());
        for (unsigned int x = 0; x < column; x++) {
            _grid[y].emplace_back(0);
        }
    }
}

void Grid::setValueAtPosition(unsigned int x, unsigned int y, int value)
{
    _grid.at(y).at(x) = value;
}