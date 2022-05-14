#include "chess.h"

void draw_figure(int cellX, int cellY, figure figure)
{
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, figure.team);
    rect cell = get_cell_coords(cellX, cellY);
    switch(figure.type)
    {
        case pawn:
            draw_pawn(cell.left, cell.top);
            break;
        case bishop:
            draw_bishop(cell.left, cell.top);
            break;
        case rook:
            draw_rook(cell.left, cell.top);
            break;
        case knight:
            draw_knight(cell.left, cell.top);
            break;
        case king:
            draw_king(cell.left, cell.top);
            break;
    }
}

void draw_pawn(int left, int top)
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

void draw_bishop(int left, int top)
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

void draw_rook(int left, int top)
{
    int plg[38];
    plg[0] = left + 15;
    plg[1] = top + 15;
    plg[2] = left + 15;
    plg[3] = top + 25;
    plg[4] = left + 20;
    plg[5] = top + 30;
    plg[6] = left + 20;
    plg[7] = top + 40;
    plg[8] = left + 15;
    plg[9] = top + 55;
    plg[10] = left + 45;
    plg[11] = top + 55;
    plg[12] = left + 40;
    plg[13] = top + 40;
    plg[14] = left + 40;
    plg[15] = top + 30;
    plg[16] = left + 45;
    plg[17] = top + 25;
    plg[18] = left + 45;
    plg[19] = top + 15;
    plg[20] = left + 40;
    plg[21] = top + 15;
    plg[22] = left + 40;
    plg[23] = top + 20;
    plg[24] = left + 35;
    plg[25] = top + 20;
    plg[26] = left + 35;
    plg[27] = top + 15;
    plg[28] = left + 25;
    plg[29] = top + 15;
    plg[30] = left + 25;
    plg[31] = top + 20;
    plg[32] = left + 25;
    plg[33] = top + 20;
    plg[34] = left + 20;
    plg[35] = top + 20;
    plg[36] = left + 20;
    plg[37] = top + 15;
    fillpoly(19, plg);
}

void draw_knight(int left, int top)
{
    int plg[34];
    plg[0] = left + 22;
    plg[1] = top + 45;
    plg[2] = left + 18;
    plg[3] = top + 55;
    plg[4] = left + 46;
    plg[5] = top + 55;
    plg[6] = left + 45;
    plg[7] = top + 48;
    plg[8] = left + 43;
    plg[9] = top + 42;
    plg[10] = left + 44;
    plg[11] = top + 30;
    plg[12] = left + 42;
    plg[13] = top + 24;
    plg[14] = left + 36;
    plg[15] = top + 12;
    plg[16] = left + 32;
    plg[17] = top + 10;
    plg[18] = left + 32;
    plg[19] = top + 16;
    plg[20] = left + 24;
    plg[21] = top + 20;
    plg[22] = left + 20;
    plg[23] = top + 24;
    plg[24] = left + 18;
    plg[25] = top + 29;
    plg[26] = left + 20;
    plg[27] = top + 34;
    plg[28] = left + 28;
    plg[29] = top + 28;
    plg[30] = left + 30;
    plg[31] = top + 30;
    plg[32] = left + 30;
    plg[33] = top + 35;
    fillpoly(17, plg);
}

void draw_king(int left, int top)
{
    int plg[48];
    plg[0] = left + 32;
    plg[1] = top + 10;
    plg[2] = left + 32;
    plg[3] = top + 15;
    plg[4] = left + 36;
    plg[5] = top + 15;
    plg[6] = left + 36;
    plg[7] = top + 18;
    plg[8] = left + 32;
    plg[9] = top + 18;
    plg[10] = left + 32;
    plg[11] = top + 22;
    plg[12] = left + 38;
    plg[13] = top + 22;
    plg[14] = left + 40;
    plg[15] = top + 26;
    plg[16] = left + 36;
    plg[17] = top + 34;
    plg[18] = left + 36;
    plg[19] = top + 46;
    plg[20] = left + 40;
    plg[21] = top + 49;
    plg[22] = left + 42;
    plg[23] = top + 55;
    plg[24] = left + 18;
    plg[25] = top + 55;
    plg[26] = left + 20;
    plg[27] = top + 49;
    plg[28] = left + 24;
    plg[29] = top + 46;
    plg[30] = left + 24;
    plg[31] = top + 34;
    plg[32] = left + 20;
    plg[33] = top + 26;
    plg[34] = left + 22;
    plg[35] = top + 22;
    plg[36] = left + 28;
    plg[37] = top + 22;
    plg[38] = left + 28;
    plg[39] = top + 18;
    plg[40] = left + 24;
    plg[41] = top + 18;
    plg[42] = left + 24;
    plg[43] = top + 15;
    plg[44] = left + 28;
    plg[45] = top + 15;
    plg[46] = left + 28;
    plg[47] = top + 10;
    fillpoly(24, plg);
}
