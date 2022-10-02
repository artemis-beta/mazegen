#include "mazegen/grid.hxx"
#include <memory>

CellArray Grid::create_grid_(const int x, const int y) {
    CellArray grid_;

    for(int i{0}; i < x; ++i) {
        std::vector<std::shared_ptr<Cell>> row_;
        for(int j{0}; j < y; ++j) {
            std::shared_ptr<Cell> cell_{new Cell(i, j)};
            row_.push_back(cell_);
        }
        grid_.push_back(row_);
    }

    return grid_;
}

void Cell::setNeighbour(Direction direction, std::shared_ptr<Cell> cell) {
    neighbours_[direction] = cell;
}

void Grid::eraseWall(int x, int y, Direction direction) {
    std::shared_ptr<Cell> this_cell_{getCell(x, y)};

    std::vector<int> offset_;

    switch(direction) {
        case Direction::UP:
            offset_ = {0, -1};
            break;
        case Direction::DOWN:
            offset_ = {0, 1};
            break;
        case Direction::RIGHT:
            offset_ = {1, 0};
            break;
        default:
            offset_ = {-1, 0};
            break;
    };

    std::shared_ptr<Cell> other_cell_{getCell(x + offset_[0], y + offset_[1])};

    this_cell_->setNeighbour(direction, other_cell_);

    if(direction == Direction::DOWN) this_cell_->eraseDown();
    else if(direction == Direction::RIGHT) this_cell_->eraseRight();

}

std::shared_ptr<Cell> Grid::getCell(int x, int y) {
    if(x > width_ - 1 || y > height_ - 1 || 0 > x || 0 > y ) {
        throw std::runtime_error(
            "Specified coordinate [" +
            std::to_string(x) +
            ", " +
            std::to_string(y) +
            "] invalid for grid of dimensions (" +
            std::to_string(width_) +
            ", " +
            std::to_string(height_) +
            ")")
        ;
    }

    return cells_[y][x];
}

std::shared_ptr<Cell> Cell::getNeighbour(Direction direction) const {
    return neighbours_.at(direction);
}

std::vector<int> Grid::getNeighbourCoordinates(const std::shared_ptr<Cell> cell, Direction direction) const {
    const std::vector<int> current_coords_{cell->getCoordinates()};

    std::vector<int> offset_;

    switch(direction) {
        case Direction::UP:
            offset_ = {0, -1};
            break;
        case Direction::DOWN:
            offset_ = {0, 1};
            break;
        case Direction::RIGHT:
            offset_ = {1, 0};
            break;
        default:
            offset_ = {-1, 0};
            break;
    };

    std::vector<int> new_coords_{current_coords_[0] + offset_[0], current_coords_[1] + offset_[1]};

    if(new_coords_[0] >= width_ || new_coords_[0] < 0) return {};
    if(new_coords_[1] >= height_ || new_coords_[1] < 0) return {};

    return new_coords_;
}
