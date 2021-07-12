#ifndef GRID_HPP_
#define GRID_HPP_

#include <vector>

class Grid {
    public:
        Grid();
        Grid(unsigned int x, unsigned int y);
        ~Grid();

        void initializeGrid(unsigned int x, unsigned int y);

        std::vector<std::vector<int>> getGrid() const;

        // \param x Column
        // \param y Line
        // \param value Value to set at pos x,y
        void setValueAtPosition(unsigned int x, unsigned int y, int value);

    protected:
    private:
        std::vector<std::vector<int>> _grid;
};

#endif /* !GRID_HPP_ */
