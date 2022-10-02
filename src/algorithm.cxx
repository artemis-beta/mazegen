#include "mazegen/algorithm.hxx"
#include "mazegen/grid.hxx"
#include <cstddef>


void binary_tree(Grid& grid) {
    std::srand(std::time(nullptr));

    const std::vector<int> dimensions_{grid.getDimensions()};

    for(int j{0}; j < dimensions_[1]; ++j) {
        for(int i{0}; i < dimensions_[0]; ++i) {
            Direction dir{static_cast<bool>(rand() % 2) ? Direction::RIGHT : Direction::DOWN};
            bool can_right_{grid.checkPermittedPath({i, j}, Direction::RIGHT)};
            bool can_down_{grid.checkPermittedPath({i, j}, Direction::DOWN)};
            if(!can_right_ && !can_down_) continue;
            if(!can_right_) dir = Direction::DOWN;
            if(!can_down_) dir = Direction::RIGHT;

            grid.linkCells({i, j}, dir);
        }
    }
}