#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Grid {
    private:
        const int width_{-1}, height_{-1};
        std::vector<std::vector<std::string>> hor_walls_;
        std::vector<std::vector<std::string>> vert_walls_;
    public:
        Grid(int x, int y) : width_{x}, height_{y} {
            hor_walls_ = std::vector<std::vector<std::string>>(height_, std::vector<std::string>(width_, "---+"));
            vert_walls_ = std::vector<std::vector<std::string>>(height_, std::vector<std::string>(width_, "   |"));
        }
        std::vector<int> getDimensions() const {return {width_, height_};}
        void linkCells(const std::vector<int>& coords_1, const Direction dir);
        void eraseHorizontalWallAt(const int x, const int y);
        void eraseVerticalWallAt(const int x, const int y);
        bool checkPermittedPath(const std::vector<int>& coords, const Direction dir) const;
        std::vector<Direction> getPermittedPaths(const std::vector<int>& coords) const;
        friend std::ostream& operator<<(std::ostream& os, Grid& grid) {
            os << "+";
            for(int i{0}; i < grid.width_; ++i) os << "---+";
            os << std::endl;
            for(int i{0}; i < 2 * grid.height_; ++i) {
                const int y_coord_{i/2};
                if(i % 2 == 0) {
                    os << "|";
                    for(int j{0}; j < grid.width_; ++j) os << grid.vert_walls_[y_coord_][j];
                    os << std::endl;
                }
                else {
                    os << "+";
                    for(int j{0}; j < grid.width_; ++j) os << grid.hor_walls_[y_coord_][j];
                    os << std::endl;
                }
            }
            return os;
        }
};