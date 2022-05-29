#include "chess.h"

// Выделяет фигуру
void mark_figure(int cellX, int cellY)
{
    figure fig = boardMap[cellX][cellY];
    if(fig.type == empty)
        return;
    draw_figure(cellX, cellY, fig, COLOR(0, 90, 255));
}

// Снимает выделение с фигуры
void unmark_figure(int cellX, int cellY)
{
    figure fig = boardMap[cellX][cellY];
    if(fig.type == empty)
        return;
    draw_figure(cellX, cellY, fig);
}

// Рисует фигуру
void draw_figure(int cellX, int cellY, figure figure, int border_color)
{
    setcolor(border_color);
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
        case queen:
            draw_queen(cell.left, cell.top);
    }
}

void draw_pawn(int left, int top)
{
    int plg[36];
    plg[0] = left + 25;
    plg[1] = top + 20;
    plg[2] = left + 35;
    plg[3] = top + 20;
    plg[4] = left + 38;
    plg[5] = top + 23;
    plg[6] = left + 38;
    plg[7] = top + 29;
    plg[8] = left + 35;
    plg[9] = top + 31;
    plg[10] = left + 39;
    plg[11] = top + 36;
    plg[12] = left + 36;
    plg[13] = top + 38;
    plg[14] = left + 38;
    plg[15] = top + 48;
    plg[16] = left + 42;
    plg[17] = top + 52;
    plg[18] = left + 42;
    plg[19] = top + 55;
    plg[20] = left + 18;
    plg[21] = top + 55;
    plg[22] = left + 18;
    plg[23] = top + 52;
    plg[24] = left + 22;
    plg[25] = top + 48;
    plg[26] = left + 24;
    plg[27] = top + 38;
    plg[28] = left + 21;
    plg[29] = top + 36;
    plg[30] = left + 25;
    plg[31] = top + 31;
    plg[32] = left + 22;
    plg[33] = top + 29;
    plg[34] = left + 22;
    plg[35] = top + 23;
    fillpoly(18, plg);
}

void draw_bishop(int left, int top)
{
    int plg[38];

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
    plg[14] = left + 22;
    plg[15] = top + 48;
    plg[16] = left + 18;
    plg[17] = top + 53;
    plg[18] = left + 18;
    plg[19] = top + 55;
    plg[20] = left + 42;
    plg[21] = top + 55;
    plg[22] = left + 42;
    plg[23] = top + 53;
    plg[24] = left + 38;
    plg[25] = top + 48;
    plg[26] = left + 35;
    plg[27] = top + 40;
    plg[28] = left + 35;
    plg[29] = top + 40;
    plg[30] = left + 35;
    plg[31] = top + 30;
    plg[32] = left + 40;
    plg[33] = top + 25;
    plg[34] = left + 35;
    plg[35] = top + 20;
    plg[36] = left + 35;
    plg[37] = top + 15;
    fillpoly(19, plg);
}

void draw_rook(int left, int top)
{
    int plg[40];
    plg[0] = left + 17;
    plg[1] = top + 15;
    plg[2] = left + 23;
    plg[3] = top + 15;
    plg[4] = left + 23;
    plg[5] = top + 19;
    plg[6] = left + 27;
    plg[7] = top + 19;
    plg[8] = left + 27;
    plg[9] = top + 15;
    plg[10] = left + 33;
    plg[11] = top + 15;
    plg[12] = left + 33;
    plg[13] = top + 19;
    plg[14] = left + 37;
    plg[15] = top + 19;
    plg[16] = left + 37;
    plg[17] = top + 15;
    plg[18] = left + 43;
    plg[19] = top + 15;
    plg[20] = left + 43;
    plg[21] = top + 23;
    plg[22] = left + 39;
    plg[23] = top + 29;
    plg[24] = left + 41;
    plg[25] = top + 44;
    plg[26] = left + 43;
    plg[27] = top + 49;
    plg[28] = left + 43;
    plg[29] = top + 55;
    plg[30] = left + 17;
    plg[31] = top + 55;
    plg[32] = left + 17;
    plg[33] = top + 49;
    plg[34] = left + 19;
    plg[35] = top + 44;
    plg[36] = left + 21;
    plg[37] = top + 29;
    plg[38] = left + 17;
    plg[39] = top + 23;
    fillpoly(20, plg);
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

void draw_queen(int left, int top)
{
    int plg[38];
    plg[0] = left + 22;
    plg[1] = top + 14;
    plg[2] = left + 26;
    plg[3] = top + 20;
    plg[4] = left + 28;
    plg[5] = top + 16;
    plg[6] = left + 30;
    plg[7] = top + 14;
    plg[8] = left + 32;
    plg[9] = top + 16;
    plg[10] = left + 34;
    plg[11] = top + 20;
    plg[12] = left + 38;
    plg[13] = top + 14;
    plg[14] = left + 38;
    plg[15] = top + 24;
    plg[16] = left + 35;
    plg[17] = top + 25;
    plg[18] = left + 40;
    plg[19] = top + 35;
    plg[20] = left + 36;
    plg[21] = top + 50;
    plg[22] = left + 40;
    plg[23] = top + 52;
    plg[24] = left + 40;
    plg[25] = top + 55;
    plg[26] = left + 20;
    plg[27] = top + 55;
    plg[28] = left + 20;
    plg[29] = top + 52;
    plg[30] = left + 24;
    plg[31] = top + 50;
    plg[32] = left + 20;
    plg[33] = top + 35;
    plg[34] = left + 25;
    plg[35] = top + 25;
    plg[36] = left + 22;
    plg[37] = top + 24;
    fillpoly(19, plg);
}
