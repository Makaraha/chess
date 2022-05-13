#include <graphics.h>
#include <stdio.h>

#ifndef CHESS_H_INCLUDED
#define CHESS_H_INCLUDED

struct point
{
    int x;
    int y;
};

struct rect
{
    int left;
    int top;
    int right;
    int bottom;
};

enum figureType
{
    empty,
    pawn, // Пешка
    king, // Король
    queen, // Ферзь
    rook, // Ладья
    knight, // Конь
    bishop // Слон
};

enum playerTeam
{
    black = BLACK,
    white = WHITE
};

struct figure
{
    figureType type;
    playerTeam team;
};


//cell
const int CELL_SIZE = 60;
int get_cell_color(int cellX, int cellY);
void clear_cell(int cellX, int cellY);
point get_cell_center(int cellX, int cellY);
rect get_cell_coords(int cellX, int cellY);

//board
const int BOARD_LEFT = 160;
const int BOARD_BOTTOM = 480;
extern figure figures[8][8];
void render_board();

//figure
void draw_figure(int cellX, int cellY, figure figure);
void draw_pawn(int x, int y);
void draw_king(int x, int y);
void draw_queen(int x, int y);
void draw_rook(int x, int y);
void draw_knight(int x, int y);
void draw_bishop(int x, int y);

#endif // CHESS_H_INCLUDED
