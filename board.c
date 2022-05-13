#include "chess.h"

void render_board()
{
    int color = DARKGRAY;

    int i = 0, j = 0;

    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            color = color == DARKGRAY ? LIGHTGRAY : DARKGRAY;
            setfillstyle(SOLID_FILL, color);
            bar(BOARD_LEFT + i * CELL_SIZE, BOARD_BOTTOM - (j + 1) * CELL_SIZE, BOARD_LEFT + (i + 1) * CELL_SIZE, BOARD_BOTTOM -  j * CELL_SIZE);
        }
        color = color == DARKGRAY ? LIGHTGRAY : DARKGRAY;
    }
}

