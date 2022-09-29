#include "mazegen/algorithm.hxx"

void binary_tree(Grid& grid) {
    std::srand(std::time(nullptr));

    const std::vector<int> dimensions_{grid.getDimensions()};

    for(int j{0}; j < dimensions_[1]; ++j) {
        for(int i{0}; i < dimensions_[0]; ++i) {
            const bool erase_south{static_cast<bool>(rand() % 2)};
            const bool can_erase_south{j < dimensions_[1] - 1};
            const bool can_erase_east{i < dimensions_[0] - 1};

            Direction erase_dir_;

            if(erase_south && can_erase_south) {
                erase_dir_ = Direction::DOWN;
            }
            else if(!erase_south && can_erase_east) {
                erase_dir_ = Direction::RIGHT;
            }
            else {
                continue;
            }

            grid.eraseWall(i, j, erase_dir_);
        }
    }
}