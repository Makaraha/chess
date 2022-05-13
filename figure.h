#include <graphics.h>

#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED

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

void draw_figure(int cellX, int cellY, figure figure);

void draw_pawn(int x, int y, int color);

void draw_king(int x, int y, int color);

void  draw_queen(int x, int y, int color);

void draw_rook(int x, int y, int color);

void draw_knight(int x, int y, int color);

void draw_bishop(int x, int y, int color);

#endif // FIGURE_H_INCLUDED
