#include "chess.h"
#include "stdio.h"

// Отлавливает нажатие кнопки мыши и перенаправляет его на другой обработчик
void click_handler()
{
    int x, y;
    while(true)
    {
        if(ismouseclick(WM_LBUTTONUP))
        {
            getmouseclick(WM_LBUTTONUP, x, y);
            if(is_board(x, y))
                board_click_handler(x, y);
        }
    }
}

// Обрабатывает нажатие на доску
void board_click_handler(int x, int y)
{
    unmark_cells();
    point cell = get_cell_by_coords(x, y);
    if(boardMap[cell.x][cell.y].type != empty && boardMap[cell.x][cell.y].team == currentMove)
    {
        int i, j;
        mark_figure(cell.x, cell.y);
        bool** moves = get_moves(cell.x, cell.y);
        for(i = 0; i < 8; i++)
            for(j = 0; j < 8; j++)
                if(moves[i][j])
                    mark_cell(i, j);
        move_handler(moves, cell.x, cell.y);
        unmark_figure(cell.x, cell.y);
        unmark_cells();
        moves_free(moves);
    }
}

// Обрабатывает нажатие на доску с выбранной фигурой.
void move_handler(bool** moves, int cellX, int cellY)
{
    int x, y;
    while(true)
    {
        if(ismouseclick(WM_LBUTTONUP))
        {
            getmouseclick(WM_LBUTTONUP, x, y);
            point cell = get_cell_by_coords(x, y);
            if(moves[cell.x][cell.y])
                move_figure(cellX, cellY, cell.x, cell.y);
            else if(boardMap[cell.x][cell.y].type == empty || boardMap[cell.x][cell.y].team != currentMove)
                continue;
            else
            {
                unmark_figure(cellX, cellY);
                board_click_handler(x, y);
            }
            break;
        }
    }
}

// Проверяет, лежат ли координаты x, y внутри доски
bool is_board(int x, int y)
{
    int left =  BOARD_LEFT;
    int bottom = BOARD_BOTTOM;
    int top = BOARD_BOTTOM - 8 * CELL_SIZE;
    int right = BOARD_LEFT + 8 * CELL_SIZE;
    return is_in_rectangle(x, y, left, top, right, bottom);
}
