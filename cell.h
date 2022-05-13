#include "common.h"

#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

const int CELL_SIZE = 60;


int get_cell_color(int cellX, int cellY);

void clear_cell(int cellX, int cellY);

point get_cell_center(int cellX, int cellY);

rect get_cell_coords(int cellX, int cellY);

#endif // CELL_H_INCLUDED
