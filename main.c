#include <graphics.h>
#include <stdio.h>
#include "board.h"
#include "cell.h"
#include "figure.h"

void init_graph()
{
    int GrDr, GrMod;
    GrDr=DETECT;
    initgraph(&GrDr,&GrMod," ");
}

int main()
{
    init_graph();
    render_board();

    figure pawnFigure;
    pawnFigure.type = bishop;
    pawnFigure.team = white;

    draw_figure(1, 1, pawnFigure);
    pawnFigure.type = pawn;
    draw_figure(1, 2, pawnFigure);
    pawnFigure.type = rook;
    draw_figure(2, 2, pawnFigure);

    char ch = getch();
    closegraph();
}
