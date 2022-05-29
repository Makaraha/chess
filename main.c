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
    fill_bg();
    render_menu();
    render_board();
    click_handler();
    closegraph();
}
