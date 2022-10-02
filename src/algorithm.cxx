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

void sidewinder(Grid &grid) {
    std::srand(std::time(nullptr));

    const std::vector<int> dimensions_{grid.getDimensions()};
    std::vector<std::vector<int>> run_cells_;

    for(int j{0}; j < dimensions_[1]; ++j) {
        for(int i{0}; i < dimensions_[0]; ++i) {
            bool link_right_{static_cast<bool>(rand() % 2)};
            if(link_right_ && grid.checkPermittedPath({i, j}, Direction::RIGHT)) {
                grid.linkCells({i, j}, Direction::RIGHT);
                run_cells_.push_back({i, j});
                continue;
            }

            std::vector<int> rand_cell_;

            if(run_cells_.size() > 0) {
                rand_cell_ = run_cells_[rand() % run_cells_.size()];
            }
            else {
                rand_cell_ = {i, j};
            }

            if(grid.checkPermittedPath(rand_cell_, Direction::DOWN)) {
                grid.linkCells(rand_cell_, Direction::DOWN);
                run_cells_.clear();
            }
        }
    }
}