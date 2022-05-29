#include "chess.h"

int get_cell_color(int cellX, int cellY)
{
    if(cellX % 2 != cellY % 2)
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

point get_cell_by_coords(int x, int y)
{
    point cellInd;
    int tempX = x - BOARD_LEFT;
    int tempY = BOARD_BOTTOM - y;
    cellInd.x = tempX / CELL_SIZE;
    cellInd.y = -(tempY / CELL_SIZE - 7);
    return cellInd;
}

void clear_cell(int cellX, int cellY)
{
    int color = get_cell_color(cellX, cellY);
    rect rect = get_cell_coords(cellX, cellY);
    setfillstyle(SOLID_FILL, color);
    bar(rect.left, rect.top, rect.right, rect.bottom);
}

void mark_cell(int cellX, int cellY, int color)
{
    rect cell = get_cell_coords(cellX, cellY);
    setcolor(color);
    rectangle(cell.left + 4, cell.top + 4, cell.right - 4, cell.bottom - 4);
}

void unmark_cell(int cellX, int cellY)
{
    rect cell = get_cell_coords(cellX, cellY);
    int color = get_cell_color(cellX, cellY);
    setcolor(color);
    rectangle(cell.left + 4, cell.top + 4, cell.right - 4, cell.bottom - 4);
}

void unmark_cells()
{
    int i, j;
    for(i = 0; i < 8; i++)
        for(j = 0; j < 8; j++)
            unmark_cell(i, j);
}
