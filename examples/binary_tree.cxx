#include "mazegen/grid.hxx"
#include "mazegen/algorithm.hxx"
#include <iostream>

int main(int argc, char** argv) {
    Grid grid_(10, 10);
    binary_tree(grid_);
    std::cout << grid_ << std::endl;
    return 0;
}