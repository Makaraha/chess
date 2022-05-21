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

extern figure boardMap[8][8];
extern playerTeam currentMove;

//moves
void set_move_cell(int cellX, int cellY, playerTeam team, bool** moves);
bool is_cell_valid(int cellX, int cellY);
bool** get_moves(int cellX, int cellY);
void get_pawn_moves(int cellX, int cellY, playerTeam team, bool** moves);
bool** moves_malloc();
void moves_free(bool** moves);
void move_handler(bool** moves, int cellX, int cellY);
void move_figure(int firstX, int firstY, int  secondX, int secondY);
void change_current_move();
void moves_reverse(bool** moves);
void get_knight_moves(int cellX, int cellY, playerTeam team, bool** moves);

//cell
const int CELL_SIZE = 60;
int get_cell_color(int cellX, int cellY);
void clear_cell(int cellX, int cellY);
point get_cell_center(int cellX, int cellY);
rect get_cell_coords(int cellX, int cellY);
point get_cell_by_coords(int x, int y);
void mark_cell(int cellX, int cellY);
void unmark_cell(int cellX, int cellY);
void unmark_cells();

//board
const int BOARD_LEFT = 160;
const int BOARD_BOTTOM = 480;
extern figure figures[8][8];
void render_board();
void set_figures();
void fill_board();
void board_reverse();

//figure
void mark_figure(int cellX, int cellY);
void unmark_figure(int cellX, int cellY);
void draw_figure(int cellX, int cellY, figure figure, int border_color = BLACK);
void draw_pawn(int x, int y);
void draw_king(int x, int y);
void draw_queen(int x, int y);
void draw_rook(int x, int y);
void draw_knight(int x, int y);
void draw_bishop(int x, int y);

//clickhanlder
bool is_board(int x, int y);
void click_handler();
void board_click_handler(int x, int y);

//common
bool is_in_rectangle(int x, int y, int left, int top, int right, int bottom);

#endif // CHESS_H_INCLUDED
