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
            if(is_game_started && is_board(x, y))
                board_click_handler(x, y);
            else
                menu_click_hanlder(x, y);
        }
    }
}
// Обрабатывает нажатие на меню
void menu_click_hanlder(int x, int y)
{
    rect newgame = get_newgame_coords();

    if(is_in_rectangle(x, y, newgame))
        start_game();

    if(is_game_started)
    {
        rect white_draw = get_draw_coords(white);
        rect black_draw = get_draw_coords(black);
        rect white_surrend = get_surrender_coords(white);
        rect black_surrend = get_surrender_coords(black);

        if(is_in_rectangle(x, y, white_draw))
            player_draw(white);
        else if(is_in_rectangle(x, y, black_draw))
            player_draw(black);
        else if(is_in_rectangle(x, y,  white_surrend))
            finish_game("Победа чёрных");
        else if(is_in_rectangle(x, y, black_surrend))
            finish_game("Победа белых");
    }

}

// Обрабатывает нажатие на доску
void board_click_handler(int x, int y)
{
    static int selectedX = -1;
    static int selectedY = -1;
    static bool is_figure_selected = false;
    static bool** moves;

    point cell = get_cell_by_coords(x, y);

    if(is_figure_selected)
    {
        unmark_figure(selectedX, selectedY);
        unmark_cells();
        is_figure_selected = false;
        if(moves[cell.x][cell.y])
            move_figure(selectedX, selectedY, cell.x, cell.y);
        else if(is_board(x, y) && (cell.x != selectedX || cell.y != selectedY))
            board_click_handler(x, y);
        moves_free(moves);
    }
    else if(boardMap[cell.x][cell.y].type != empty && boardMap[cell.x][cell.y].team == currentMove)
    {
        int i, j;
        moves = moves_malloc();
        mark_figure(cell.x, cell.y);
        get_moves(cell.x, cell.y, moves);
        for(i = 0; i < 8; i++)
            for(j = 0; j < 8; j++)
                if(moves[i][j])
                    mark_cell(i, j, COLOR(0, 90, 255));
        selectedX = cell.x;
        selectedY = cell.y;
        is_figure_selected = true;
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
