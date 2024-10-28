#ifndef SOLVER_H
#define SOLVER_H

#include <stdbool.h>

#include "sudoku.h"

#define solve_all(board) _solve_all(board, 0)

void solve(Board *board);

void _solve_all(Board *board, uint32_t square);

#endif
