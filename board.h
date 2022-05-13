#include "figure.h"

#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

const int BOARD_LEFT = 160;
const int BOARD_BOTTOM = 480;

extern figure figures[8][8];

void render_board();

#endif // BOARD_H_INCLUDED
