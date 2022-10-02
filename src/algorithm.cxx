#include "mazegen/algorithm.hxx"
#include "mazegen/grid.hxx"
#include <memory>
#include <stdexcept>
#include <string>

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

void aldous_broder(Grid& grid) {

    std::ofstream outs("out.dat");

    std::srand(std::time(nullptr));

    std::vector<std::string> visited_;

    const std::vector<int> dimensions_{grid.getDimensions()};

    std::shared_ptr<Cell> current_cell_{grid.getCell(rand() % dimensions_[0], rand() % dimensions_[1])};

    std::vector<int> current_coords_{current_cell_->getCoordinates()};

    outs << "x" << "," << "y" << std::endl;
    outs << current_coords_[0] << "," << current_coords_[1] << std::endl;

    std::shared_ptr<Cell> neighbour_{current_cell_};

    visited_.push_back(std::to_string(current_coords_[0]) + std::to_string(current_coords_[1]));

    while(visited_.size() < dimensions_[0] * dimensions_[1]) {
        std::vector<Direction> permitted_;
        current_coords_ = {current_cell_->getCoordinates()};

        std::vector<int> neighbour_coords_;

        for(int k{0}; k < 4; ++k) {
            const Direction dir{static_cast<Direction>(k)};
            neighbour_coords_ = {grid.getNeighbourCoordinates(current_cell_, dir)};
            if(neighbour_coords_.size() == 0) continue;
            permitted_.push_back(dir);
        }

        Direction rand_dir_;

        rand_dir_ = permitted_[rand() % permitted_.size()];
        neighbour_coords_ = {grid.getNeighbourCoordinates(current_cell_, rand_dir_)};
        neighbour_ = grid.getCell(neighbour_coords_[0], neighbour_coords_[1]);

        if(std::find(visited_.begin(), visited_.end(), std::to_string(neighbour_coords_[0]) + std::to_string(neighbour_coords_[1])) == visited_.end()) {
            grid.eraseWall(current_coords_[0], current_coords_[1], rand_dir_);
            visited_.push_back(std::to_string(neighbour_coords_[0]) + std::to_string(neighbour_coords_[1]));
        }

        outs << current_coords_[0] << "," << current_coords_[1] << std::endl;

        current_cell_ = neighbour_;
    }

    outs.close();
}
