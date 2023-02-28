#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

// posible delete
void interface_initialization()
{
    int mrow, mcol;
    initscr();
    raw();
    start_color();
    // init_pair(1, COLOR_RED, COLOR_BLACK);
    refresh();
    getmaxyx(stdscr, mrow, mcol);
    mvprintw(0, mcol / 2 - 4, "BLACKJACK");
    mvprintw(5, 8, "DEALER");
    mvprintw(5, mcol - 20, "YOU");
    mvprintw(9, 8, "HAND VALUE:");
    mvprintw(9, mcol - 20, "HAND VALUE:");
    mvprintw(mrow - 10, 40, "HIT (Press H)");
    mvprintw(mrow - 8, 40, "STAND (Press S)");
    getch();
    endwin();
}

void update_player_hand(char *hand, int mcol)
{
    int i, movement = 0;
    for (i = 0; i < strlen(hand); i++)
    {
        if (hand[i] == 'T')
        {
            mvprintw(7, mcol - 20 + movement, "10 ");
            movement += 3;
        }
        else
        {
            mvprintw(7, mcol - 20 + movement, "%c ", hand[i]);
            movement += 2;
        }
    }
}

void update_dealer_hand(char *hand)
{
    int i, movement = 0;
    for (i = 0; i < strlen(hand); i++)
    {
        if (hand[i] == 'T')
        {
            mvprintw(7, 8 + movement, "10 ");
            movement += 3;
        }
        else
        {
            mvprintw(7, 8 + movement, "%c ", hand[i]);
            movement += 2;
        }
    }
}

void update_player_value(int value, int mcol)
{
    mvprintw(9, mcol - 8, "%d", value);
}

void update_dealer_value(int value, int mcol)
{
    mvprintw(9, 20, "%d", value);
}

void hide_dealer_hand(char *hand)
{
    int i, movement = 2;
    mvprintw(7, 8, "? ");
    for (i = 1; i < strlen(hand); i++)
    {
        if (hand[i] == 'T')
        {
            mvprintw(7,8+movement,"10 ");
            movement+=3;
        }
        else
        {
            mvprintw(7,8+movement,"%c ", hand[i]);
            movement+=2;
        }
    }
}