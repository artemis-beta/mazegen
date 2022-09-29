#pragma once

#include <vector>
#include <map>
#include <memory>
#include <string>
#include <stdexcept>
#include <iostream>

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Cell {
    private:
        const int x_{-1}, y_{-1};
        std::map<Direction, std::shared_ptr<Cell>> neighbours_{
            {Direction::UP, nullptr},
            {Direction::DOWN, nullptr},
            {Direction::LEFT, nullptr},
            {Direction::RIGHT, nullptr}
        };
        char east_wall_ = '|';
        char south_wall_ = '_';
    public:
        void setNeighbour(Direction direction, std::shared_ptr<Cell> cell);
        void eraseRight() {east_wall_ = ' ';}
        void eraseDown() {south_wall_ = ' ';}
        Cell() {}
        Cell(int x, int y) : x_(x), y_(y) {}

        friend std::ostream& operator<<(std::ostream& os, Cell& cell) {
            os << cell.south_wall_ << cell.east_wall_;
            return os;
        }
};

typedef std::vector<std::vector<std::shared_ptr<Cell>>> CellArray;

class Grid {
    private:
        const CellArray cells_;
        const int width_{-1}, height_{-1};
        CellArray create_grid_(int x, int y);
    public:
        std::shared_ptr<Cell> getCell(int x, int y);
        Grid(int width, int height) : cells_(create_grid_(width, height)), width_(width), height_(height) {}
        void eraseWall(int x, int y, Direction direction);
        std::vector<int> getDimensions() const {return {width_, height_};} 
        friend std::ostream& operator<<(std::ostream& os, Grid& grid) {
            os << ' ';
            for(int i{0}; i < grid.width_; ++i) os << "_ ";
            os << std::endl;
            for(int i{0}; i < grid.width_; ++i) {
                os << "|";
                for(int j{0}; j < grid.height_; ++j) {
                    os << *grid.getCell(i, j);
                }
                os << std::endl;
            }
            return os;
        }
};