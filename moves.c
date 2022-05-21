#include "chess.h"
#include <stdio.h>

// Меняет очередь хода
void change_current_move()
{
    if(currentMove == white)
        currentMove = black;
    else
        currentMove = white;
}

// Двигает фигуру из ячейки 1 в ячейку 2
void move_figure(int firstX, int firstY, int secondX, int secondY)
{
    figure fig = boardMap[firstX][firstY];
    boardMap[firstX][firstY].type = empty;
    boardMap[secondX][secondY] = fig;
    clear_cell(firstX, firstY);
    clear_cell(secondX, secondY);
    draw_figure(secondX, secondY, fig);
    change_current_move();
}

// Возвращает матрицу ходов, которые может сделать фигура
bool** get_moves(int cellX, int cellY)
{
    figure fig =  boardMap[cellX][cellY];
    bool** moves = moves_malloc();

    if(fig.team == black)
    {
        board_reverse();
        cellX = 7 - cellX;
        cellY = 7 - cellY;
    }

    switch(fig.type)
    {
        case pawn:
            get_pawn_moves(cellX, cellY, fig.team, moves);
            break;
        case knight:
            get_knight_moves(cellX, cellY, fig.team, moves);
            break;
    }

    if(fig.team == black)
    {
        moves_reverse(moves);
        board_reverse();
    }


    return moves;
}

// Заполняет матрицу ходов пешки
void get_pawn_moves(int cellX, int cellY, playerTeam team, bool** moves)
{
    printf("cur: %d %d\n", cellX, cellY);

    if(cellY == 0)
        return;

    set_move_cell(cellX, cellY - 1, team, moves);

    if(cellY == 6 && moves[cellX][cellY - 1])
        set_move_cell(cellX, cellY - 2, team, moves);

    if(is_cell_valid(cellX + 1, cellY - 1) && boardMap[cellX + 1][cellY - 1].type != empty)
        set_move_cell(cellX + 1, cellY - 1, team, moves);

    if(is_cell_valid(cellX - 1, cellY + 1), boardMap[cellX - 1][cellY - 1].type != empty)
        set_move_cell(cellX - 1, cellY - 1, team, moves);
}

void get_knight_moves(int cellX, int cellY, playerTeam team, bool** moves)
{
    set_move_cell(cellX - 2, cellY - 1, team, moves);
    set_move_cell(cellX - 2, cellY + 1, team, moves);
    set_move_cell(cellX + 2, cellY - 1, team, moves);
    set_move_cell(cellX + 2, cellY + 1, team, moves);
    set_move_cell(cellX - 1, cellY - 2, team, moves);
    set_move_cell(cellX - 1, cellY + 2, team, moves);
    set_move_cell(cellX + 1, cellY - 2, team, moves);
    set_move_cell(cellX + 1, cellY + 2, team, moves);
}


// Разрешает или запрещает ход в ячейку
void set_move_cell(int cellX, int cellY, playerTeam team, bool** moves)
{
    if(is_cell_valid(cellX, cellY) && (boardMap[cellX][cellY].type == empty || boardMap[cellX][cellY].team != team))
        moves[cellX][cellY] = true;
}

// Проверяет валидность координат ячейки
bool is_cell_valid(int cellX, int cellY)
{
    return cellX >= 0 && cellX <= 7 && cellY >= 0 && cellY <= 7;
}

// Выделяет память для матрицы ходов
bool** moves_malloc()
{
    int i, j;
    bool** moves = (bool**)malloc(8 * sizeof(bool*));
    for(i = 0; i < 8; i++)
    {
        moves[i] = (bool*)malloc(8 * sizeof(bool));
        for(j = 0; j < 8; j++)
            moves[i][j] = false;
    }


    return moves;
}

// Освобождает память для матрицы ходов
void moves_free(bool** moves)
{
    int i;
    for(i = 0; i < 8; i++)
        free(moves[i]);
    free(moves);
}

// Зеркалит матрицу ходов
void moves_reverse(bool** moves)
{
    int i, j;
    bool temp;
    for(i = 0; i < 4; i++)
        for(j = 0; j < 8; j++)
        {
            temp = moves[i][j];
            moves[i][j] = moves[7 - i][7 - j];
            moves[7 - i][7 - j] = temp;
        }
}
