#include "mazegen/algorithm.hxx"

void binary_tree(Grid& grid) {
    std::srand(std::time(nullptr));

    const std::vector<int> dimensions_{grid.getDimensions()};

    for(int j{0}; j < dimensions_[1] - 1; ++j) {
        for(int i{0}; i < dimensions_[0] - 1; ++i) {

            const bool erase_south_{static_cast<bool>(rand() % 2)};

            Direction erase_dir_ = (erase_south_) ? Direction::DOWN : Direction::RIGHT;

            grid.eraseWall(i, j, erase_dir_);
        }
    }
}

void sidewinder(Grid& grid) {
    std::srand(std::time(nullptr));

    const std::vector<int> dimensions_{grid.getDimensions()};

    for(int j{0}; j < dimensions_[1]-1; ++j) {
        std::vector<std::vector<int>> run_;
        for(int i{0}; i < dimensions_[0]-1; ++i) {

            bool erase_east{static_cast<bool>(rand() % 2)};

            if(erase_east) {
                if(i == dimensions_[0]) {
                    grid.eraseWall(i, j, Direction::DOWN);
                    run_.push_back({i, j});
                }
                else {
                    grid.eraseWall(i, j, Direction::RIGHT);
                }
            }
            else {
                run_.push_back({i, j});
                const int rand_index_{static_cast<int>(rand() % run_.size())};
                grid.eraseWall(run_[rand_index_][0], run_[rand_index_][1], Direction::DOWN);
                run_.clear();
            }
        }
    }
}