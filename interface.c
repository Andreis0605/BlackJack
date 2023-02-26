#include <ncurses.h>
#include "interface.h"

void interface_initialization()
{
    int mrow, mcol;
    initscr();
    raw();
    start_color();
    //init_pair(1, COLOR_RED, COLOR_BLACK);
    refresh();
    getmaxyx(stdscr, mrow, mcol);
    mvprintw(0,mcol/2-4,"BLACKJACK");
    mvprintw(5,10,"DEALER");
    mvprintw(5,mcol-13,"YOU");
    getch();
    endwin();
}