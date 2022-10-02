#include "mazegen/grid.hxx"
#include "mazegen/algorithm.hxx"
#include <iostream>

int main(int argc, char** argv) {

    int x_{10}, y_{10};

    if(argc > 1) {
        if(argc < 3) {
            std::cout << "Expected two arguments for dimensions (x, y)" << std::endl;
            return 1;
        }
        x_ = std::atoi(argv[1]);
        y_ = std::atoi(argv[2]);
    }
    Grid grid_(x_, y_);
    aldous_broder(grid_);
    std::cout << grid_ << std::endl;
    return 0;
}