#pragma once

#include <cstdlib>
#include <ctime>

#include "mazegen/grid.hxx"

void binary_tree(Grid& grid);
void sidewinder(Grid& grid);
void erase_random_(Grid& grid, std::vector<std::vector<int>>& run);