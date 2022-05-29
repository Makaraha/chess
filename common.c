#include "chess.h"

int BACKGROUND_COLOR = COLOR(25, 25, 25);

// Проверяет, находится ли точка внутри прямоугольника
bool is_in_rectangle(int x, int y, int left, int top, int right, int bottom)
{
    return x >= left && x <= right && y <= bottom && y >= top;
}

bool is_in_rectangle(int x, int y, rect rec)
{
    return is_in_rectangle(x, y, rec.left, rec.top, rec.right, rec.bottom);
}

// Заполняет фон
void fill_bg()
{
    setfillstyle(SOLID_FILL, COLOR(25, 25, 25));
    bar(0, 0, 479, 639);
}

// Рисует текст по координате центральной точки
void draw_text_by_center(int x, int y, char* text)
{
    int ysize = textheight(text);
    int xsize = textwidth(text);
    outtextxy(x - xsize / 2, y - ysize / 2, text);
}

// Возвращает координаты текста
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

// Возвращает изображение экрана
void* screenshot()
{
    unsigned size = imagesize(0, 0, 639, 479);
    void *buffer = malloc(size);
    getimage(0, 0, 639, 479, buffer);
    return buffer;
}

playerTeam operator ! (playerTeam team)
{
    if(team == black)
        return white;
    return black;
}
