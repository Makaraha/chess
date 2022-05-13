#include "chess.h"

int get_cell_color(int cellX, int cellY)
{
    if(cellX + cellY % 2 == 0)
        return LIGHTGRAY;
    return DARKGRAY;
}

point get_cell_center(int cellX, int cellY)
{
    point point;
    int left = BOARD_LEFT + CELL_SIZE * cellX;
    int bottom = BOARD_BOTTOM + CELL_SIZE * cellY;
    point.x = left + CELL_SIZE / 2;
    point.y = bottom - CELL_SIZE / 2;
    return point;
}

rect get_cell_coords(int cellX, int cellY)
{
    rect rect;
    rect.left = BOARD_LEFT + CELL_SIZE * cellX;
    rect.top = BOARD_BOTTOM  - CELL_SIZE * (8 - cellY);
    rect.right = rect.left + CELL_SIZE;
    rect.bottom = rect.top + CELL_SIZE;
    return rect;
}

void clear_cell(int cellX, int cellY)
{
    int color = get_cell_color(cellX, cellY);
    rect rect = get_cell_coords(cellX, cellY);
    setfillstyle(SOLID_FILL, color);
    bar(rect.left, rect.top, rect.right, rect.bottom);
    printf("%d %d %d %d", rect.left, rect.top, rect.right, rect.bottom);
}
