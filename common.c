#include "chess.h"

bool is_in_rectangle(int x, int y, int left, int top, int right, int bottom)
{
    return x >= left && x <= right && y <= bottom && y >= top;
}
