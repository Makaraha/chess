#include "chess.h"

void draw_figure(int cellX, int cellY, figure figure)
{
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, figure.team);
    rect cell = get_cell_coords(cellX, cellY);
    switch(figure.type)
    {
        case pawn:
            draw_pawn(cell.left, cell.top, figure.team);
            break;
        case bishop:
            draw_bishop(cell.left, cell.top, figure.team);
            break;
        case rook:
            draw_rook(cell.left, cell.top, figure.team);
            break;
    }
}

void draw_pawn(int left, int top, int color)
{
    int plg[36];
    plg[0] = left + 25;
    plg[1] = top + 15;
    plg[2] = left + 35;
    plg[3] = top + 15;
    plg[4] = left + 40;
    plg[5] = top + 20;
    plg[6] = left + 40;
    plg[7] = top + 25;
    plg[8] = left + 35;
    plg[9] = top + 30;
    plg[10] = left + 40;
    plg[11] = top + 35;
    plg[12] = left + 35;
    plg[13] = top + 35;
    plg[14] = left + 35;
    plg[15] = top + 40;
    plg[16] = left + 40;
    plg[17] = top + 45;
    plg[18] = left + 45;
    plg[19] = top + 55;
    plg[20] = left + 15;
    plg[21] = top + 55;
    plg[22] = left + 20;
    plg[23] = top + 45;
    plg[24] = left + 25;
    plg[25] = top + 40;
    plg[26] = left + 25;
    plg[27] = top + 35;
    plg[28] = left + 20;
    plg[29] = top + 35;
    plg[30] = left + 25;
    plg[31] = top + 30;
    plg[32] = left + 20;
    plg[33] = top + 25;
    plg[34] = left + 20;
    plg[35] = top + 20;
    fillpoly(18, plg);
}

void draw_bishop(int left, int top, int color)
{
    int plg[30];
    plg[0] = left + 30;
    plg[1] = top + 10;
    plg[2] = left + 25;
    plg[3] = top + 15;
    plg[4] = left + 30;
    plg[5] = top + 20;
    plg[6] = left + 25;
    plg[7] = top + 20;
    plg[8] = left + 20;
    plg[9] = top + 25;
    plg[10] = left + 25;
    plg[11] = top + 30;
    plg[12] = left + 25;
    plg[13] = top + 40;
    plg[14] = left + 15;
    plg[15] = top + 55;
    plg[16] = left + 45;
    plg[17] = top + 55;
    plg[18] = left + 35;
    plg[19] = top + 40;
    plg[20] = left + 35;
    plg[21] = top + 40;
    plg[22] = left + 35;
    plg[23] = top + 30;
    plg[24] = left + 40;
    plg[25] = top + 25;
    plg[26] = left + 35;
    plg[27] = top + 20;
    plg[28] = left + 35;
    plg[29] = top + 15;
    fillpoly(15, plg);
}

void draw_rook(int left, int top, int color)
{
    int plg[38];
    plg[0] = left + 15;
    plg[1] = top + 15;
    plg[2] = left + 15;
    plg[3] = top + 25;
    plg[4] = left + 25;
    plg[5] = top + 25;
    plg[6] = left + 25;
    plg[7] = top + 35;
    plg[8] = left + 20;
    plg[9] = top + 40;
    plg[10] = left + 15;
    plg[11] = top + 55;
    plg[12] = left + 45;
    plg[13] = top + 55;
    plg[14] = left + 40;
    plg[15] = top + 40;
    plg[16] = left + 35;
    plg[17] = top + 35;
    plg[18] = left + 35;
    plg[19] = top + 25;
    plg[20] = left + 45;
    plg[21] = top + 25;
    plg[22] = left + 45;
    plg[23] = top + 15;
    plg[24] = left + 40;
    plg[25] = top + 10;
    plg[26] = left + 40;
    plg[27] = top + 20;
    plg[28] = left + 35;
    plg[29] = top + 20;
    plg[30] = left + 30;
    plg[31] = top + 15;
    plg[32] = left + 25;
    plg[33] = top + 20;
    plg[34] = left + 20;
    plg[35] = top + 20;
    plg[36] = left + 20;
    plg[37] = top + 10;
    fillpoly(19, plg);
}
