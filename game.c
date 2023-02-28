#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ncurses.h>
#include "deck_operations.h"
#include "interface.h"
#include "player.h"
#include "dealer.h"

int main()
{
    int playing=1,aux_card_value,deck[53];
    char dealer_hand[12],player_hand[12],aux_card;

    strcpy(dealer_hand,"\0");
    strcpy(player_hand,"\0");

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
    while(playing)
    {
        aux_card_value=draw_card(deck);
        aux_card=card_translation(aux_card_value);
        player_add_in_hand(player_hand,aux_card);

        aux_card_value=draw_card(deck);
        aux_card=card_translation(aux_card_value);
        dealer_add_in_hand(dealer_hand,aux_card);

        aux_card_value=draw_card(deck);
        aux_card=card_translation(aux_card_value);
        player_add_in_hand(player_hand,aux_card);

        aux_card_value=draw_card(deck);
        aux_card=card_translation(aux_card_value);
        dealer_add_in_hand(dealer_hand,aux_card);

        hide_dealer_hand(dealer_hand);
        update_player_hand(player_hand,mcol);
        playing=0;
    }
    getch();
    endwin();
    return 0;
}
