# Mazes for Programmers in C++

This repository contains code following the outline algorithms in _Mazes for Programmers_ by Jamis Buck, which can be found [here](http://www.mazesforprogrammers.com/).

_mazegen_ is a library containing maze construction algorithms which can be applied to a grid class.

## Algorithms

For all these approaches a grid of squares is constructed. In this context the term 'wall' refers to the boundary between two cells within the grid.

### Binary Tree

In the binary tree algorithm each cell of the grid is visited and a coin is tossed, the result determines if either the northern or eastern wall is erased (where possible). This is the simplest algorithm, although not the best in terms of results. The `binary_tree` example within the examples folder demonstrates the results.

![binary_tree_demo](./img/binary_tree_demo.png)