#include "mazegen/grid.hxx"
#include <stdexcept>

void Grid::eraseHorizontalWallAt(const int x, const int y) {
    hor_walls_[y][x] = "   +";
}

void Grid::eraseVerticalWallAt(const int x, const int y) {
    vert_walls_[y][x] = "    ";
}

std::vector<Direction> Grid::getPermittedPaths(const std::vector<int>& coords) const {
    std::vector<Direction> permitted_;

    for(int i{0}; i < 4; ++i) {
        const Direction dir{static_cast<Direction>(i)};
        if(checkPermittedPath(coords, dir)) permitted_.push_back(dir);
    }

    return permitted_;
}

bool Grid::checkPermittedPath(const std::vector<int>& coords, const Direction dir) const {
    const bool no_right_{coords[0] >= width_ - 1 && dir == Direction::RIGHT};
    const bool no_left_{coords[0] < 1 && dir == Direction::LEFT};
    const bool no_up_{coords[1] < 1 && dir == Direction::UP};
    const bool no_down_{coords[1] >= height_ - 1 && dir == Direction::DOWN};

    return (!no_right_ && !no_left_ && !no_up_ && !no_down_);
}

void Grid::linkCells(const std::vector<int>& coords_1, const Direction dir) {

    if(!checkPermittedPath(coords_1, dir)) {
        throw std::runtime_error("Invalid path selection");
    }
    
    switch(dir) {
        case Direction::LEFT:
            eraseVerticalWallAt(coords_1[0] - 1, coords_1[1]);
            break;
        case Direction::RIGHT:
            eraseVerticalWallAt(coords_1[0], coords_1[1]);
            break;
        case Direction::UP:
            eraseHorizontalWallAt(coords_1[0], coords_1[1] - 1);
            break;
        default:
            eraseHorizontalWallAt(coords_1[0], coords_1[1]);
            break;
    }
}