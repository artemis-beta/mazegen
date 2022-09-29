#include "mazegen/algorithm.hxx"

void binary_tree(Grid& grid) {
    std::srand(std::time(nullptr));

    const std::vector<int> dimensions_{grid.getDimensions()};

    for(int j{0}; j < dimensions_[1] - 1; ++j) {
        for(int i{0}; i < dimensions_[0] - 1; ++i) {

            const bool erase_south{static_cast<bool>(rand() % 2)};

            Direction erase_dir_ = (erase_south) ? Direction::DOWN : Direction::RIGHT;

            grid.eraseWall(i, j, erase_dir_);
        }
    }
}