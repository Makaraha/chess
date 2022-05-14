#include "chess.h"

figure boardMap[8][8];

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

void set_figures()
{
    int i, j;

    for(i = 0; i < 8; i++)
        for(j = 0; j < 8; j++)
            boardMap[i][j] = { empty, black };

    for(i = 0; i < 8; i++)
    {
        boardMap[i][1] = { pawn, black };
        boardMap[i][6] = { pawn, white };
    }

    boardMap[0][0] = { rook, black };
    boardMap[7][0] = { rook, black };
    boardMap[7][7] = { rook, white };
    boardMap[0][7] = { rook, white };

    boardMap[1][0] = { knight, black };
    boardMap[6][0] = { knight, black };
    boardMap[1][7] = { knight, white };
    boardMap[6][7] = { knight, white };

    boardMap[2][0] = { bishop, black };
    boardMap[5][0] = { bishop, black };
    boardMap[2][7] = { bishop, white };
    boardMap[5][7] = { bishop, white };

    boardMap[3][0] = { queen, black };
    boardMap[3][7] = { queen, white };

    boardMap[4][0] = { king, black };
    boardMap[4][7] = { king, white };

    for(i = 0; i < 8; i++)
        for(j = 0; j < 8; j++)
            draw_figure(i, j, boardMap[i][j]);
}

