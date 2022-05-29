#include "chess.h"
#include <stdio.h>

// Меняет очередь хода
void change_current_move()
{
    if(currentMove == white)
    {
        currentMove = black;
        draw_menu_team(WHITE, white);
        draw_menu_team(LIGHTGREEN, black);
    }
    else
    {
        currentMove = white;
        draw_menu_team(WHITE, black);
        draw_menu_team(LIGHTGREEN, white);
    }
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
void get_moves(int cellX, int cellY, bool** moves, bool all_moves)
{
    figure fig =  boardMap[cellX][cellY];

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
        case bishop:
            get_bishop_moves(cellX, cellY, fig.team, moves);
            break;
        case rook:
            get_rook_moves(cellX, cellY, fig.team, moves);
            break;
        case queen:
            get_queen_moves(cellX, cellY, fig.team, moves);
            break;
        case king:
            get_king_moves(cellX, cellY, fig.team, moves);
            break;
    }

    if(!all_moves)
    {
        bool** enemyMoves = moves_malloc();
        get_moves_covering(!fig.team, enemyMoves);
        remove_check_moves(cellX, cellY, moves);
        moves_free(enemyMoves);
    }

    if(fig.team == black)
    {
        moves_reverse(moves);
        board_reverse();
    }
}

// Удаляет ходы, приводящие к шаху
void remove_check_moves(int cellX, int cellY, bool** moves)
{
    int i, j;
    figure fig = boardMap[cellX][cellY];
    printf("\n");
    for(i = 0; i < 8; i++)
        for(j = 0; j < 8; j++)
        {
            if(moves[i][j])
            {
                figure from = boardMap[cellX][cellY];
                figure to = boardMap[i][j];

                boardMap[i][j] = fig;
                boardMap[cellX][cellY].type = empty;

                point kingCell = find_king(fig.team);

                bool** enemyMoves = moves_malloc();
                get_moves_covering(!fig.team, enemyMoves);
                if(enemyMoves[kingCell.x][kingCell.y])
                {
                    moves[i][j] = false;
                    printf("fig %d %d\n", cellX, cellY);
                    printf("check %d %d\n", i, j);
                    printf("king %d %d\n", kingCell.x, kingCell.y);
                }
                moves_free(enemyMoves);

                boardMap[cellX][cellY] = from;
                boardMap[i][j] = to;
            }
        }
}

// Заполняет матрицу ходов пешки
void get_pawn_moves(int cellX, int cellY, playerTeam team, bool** moves)
{
    if(boardMap[cellX][cellY - 1].type == empty)
        set_move_cell(cellX, cellY - 1, team, moves);

    if(cellY == 6 && moves[cellX][cellY - 1] && boardMap[cellX][cellY - 2].type == empty)
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

// Заполняет матрицу ходов слона
void get_bishop_moves(int cellX, int cellY, playerTeam team, bool** moves)
{
    int i;
    for(i = 1; i < 8; i++)
    {
        if(i == 1 || (is_cell_valid(cellX + i - 1, cellY + i - 1) && moves[cellX + i - 1][cellY + i - 1] && boardMap[cellX + i - 1][cellY + i - 1].type == empty))
            set_move_cell(cellX + i, cellY + i, team, moves);

        if(i == 1 || (is_cell_valid(cellX - i + 1, cellY - i + 1) && moves[cellX - i + 1][cellY - i + 1] && boardMap[cellX - i + 1][cellY - i + 1].type == empty))
            set_move_cell(cellX - i, cellY - i, team, moves);

        if(i == 1 || (is_cell_valid(cellX - i + 1, cellY + i - 1) && moves[cellX - i + 1][cellY + i - 1] && boardMap[cellX - i + 1][cellY + i - 1].type == empty))
            set_move_cell(cellX - i, cellY + i, team, moves);

        if(i == 1 || (is_cell_valid(cellX + i - 1, cellY - i + 1) && moves[cellX + i - 1][cellY - i + 1] && boardMap[cellX + i - 1][cellY - i + 1].type == empty))
            set_move_cell(cellX + i, cellY - i, team, moves);
    }
}

// Заполняет матрицу ходов ладьи
void get_rook_moves(int cellX, int cellY, playerTeam team, bool** moves)
{
    int i;
    for(i = 1; i < 8; i++)
    {
        if(i == 1 || (is_cell_valid(cellX, cellY + i - 1) && moves[cellX][cellY + i - 1] && boardMap[cellX][cellY + i - 1].type == empty))
            set_move_cell(cellX, cellY + i, team, moves);

        if(i == 1 || (is_cell_valid(cellX - i + 1, cellY) && moves[cellX - i + 1][cellY] && boardMap[cellX - i + 1][cellY].type == empty))
            set_move_cell(cellX - i, cellY, team, moves);

        if(i == 1 || (is_cell_valid(cellX, cellY - i + 1) && moves[cellX][cellY - i + 1] && boardMap[cellX][cellY - i + 1].type == empty))
            set_move_cell(cellX, cellY - i, team, moves);

        if(i == 1 || (is_cell_valid(cellX + i - 1, cellY) && moves[cellX + i - 1][cellY] && boardMap[cellX + i - 1][cellY].type == empty))
            set_move_cell(cellX + i, cellY, team, moves);
    }
}

// Заполняет матрицу ходов ферзя
void get_queen_moves(int cellX, int cellY, playerTeam team, bool** moves)
{
    get_bishop_moves(cellX, cellY, team, moves);
    get_rook_moves(cellX, cellY, team, moves);
}

// Заполняет матрицу ходов короля
void get_king_moves(int cellX, int cellY, playerTeam team, bool** moves)
{
    set_move_cell(cellX - 1, cellY - 1, team, moves);
    set_move_cell(cellX - 1, cellY + 1, team, moves);
    set_move_cell(cellX + 1, cellY - 1, team, moves);
    set_move_cell(cellX + 1, cellY + 1, team, moves);
    set_move_cell(cellX - 1, cellY, team, moves);
    set_move_cell(cellX, cellY + 1, team, moves);
    set_move_cell(cellX + 1, cellY, team, moves);
    set_move_cell(cellX, cellY - 1, team, moves);
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

// Получает покрытие ходов для данного игрока
void get_moves_covering(playerTeam team, bool** moves)
{
    int i, j;
    for(i = 0; i < 8; i++)
        for(j = 0; j < 8; j++)
            if(boardMap[i][j].team == team && boardMap[i][j].type != empty)
                get_moves(i, j, moves, true);
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
