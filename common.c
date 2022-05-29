#include "chess.h"

int BACKGROUND_COLOR = COLOR(25, 25, 25);

bool is_in_rectangle(int x, int y, int left, int top, int right, int bottom)
{
    return x >= left && x <= right && y <= bottom && y >= top;
}

bool is_in_rectangle(int x, int y, rect rec)
{
    return is_in_rectangle(x, y, rec.left, rec.top, rec.right, rec.bottom);
}

void fill_bg()
{
    setfillstyle(SOLID_FILL, COLOR(25, 25, 25));
    bar(0, 0, 479, 639);
}

// –исует текст по координате центральной точки
void draw_text_by_center(int x, int y, char* text)
{
    int ysize = textheight(text);
    int xsize = textwidth(text);
    outtextxy(x - xsize / 2, y - ysize / 2, text);
}

// ¬озвращает координаты текста
rect get_text_coords(int x, int y, char* text)
{
    int ysize = textheight(text);
    int xsize = textwidth(text);
    x -= xsize / 2;
    y -= ysize / 2;

    rect rec;
    rec.bottom = y + ysize;
    rec.top = y;
    rec.left = x;
    rec.right = x + xsize;
    return rec;
}

playerTeam operator ! (playerTeam team)
{
    if(team == black)
        return white;
    return black;
}
