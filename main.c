#include "chess.h"

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
    set_figures();
    click_handler();
    closegraph();
}
