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
    int playing = 1, aux_card_value, deck[53], player_turn, aux_value,dealer_turn;
    char dealer_hand[12], player_hand[12], aux_card, action;

    strcpy(dealer_hand, "\0");
    strcpy(player_hand, "\0");

    int mrow, mcol;
    initscr();
    raw();
    noecho();
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

    while (playing)
    {
        //"shuffle the deck"
        initialize_deck(deck);

        // giving initial cards
        aux_card_value = draw_card(deck);
        aux_card = card_translation(aux_card_value);
        player_add_in_hand(player_hand, aux_card);

        aux_card_value = draw_card(deck);
        aux_card = card_translation(aux_card_value);
        dealer_add_in_hand(dealer_hand, aux_card);

        aux_card_value = draw_card(deck);
        aux_card = card_translation(aux_card_value);
        player_add_in_hand(player_hand, aux_card);

        aux_card_value = draw_card(deck);
        aux_card = card_translation(aux_card_value);
        dealer_add_in_hand(dealer_hand, aux_card);

        // display the hands

        update_player_hand(player_hand, mcol);
        hide_dealer_hand(dealer_hand);

        // display the current value of the players hand
        aux_card_value = hand_value(player_hand);
        update_player_value(aux_card_value, mcol);

        // starting the player's turn
        player_turn = 1;
        while (player_turn)
        {
            // getting the input from the player
            refresh();
            action = getch();
            switch (action)
            {
            case 'h':
                // 'h' causes to draw a new card from the deck and add it
                // to the player's hand
                aux_card_value = draw_card(deck);
                aux_card = card_translation(aux_card_value);
                player_add_in_hand(player_hand, aux_card);
                update_player_hand(player_hand, mcol);

                // calculating the player's new hand value and
                // displaying a message if that is the case and
                // stopping the players turn
                aux_value = hand_value(player_hand);
                if (aux_value > 21)
                {
                    player_bust(mcol);
                    player_turn = 0;
                }
                if (aux_value == 21)
                {
                    player_blackjack(mcol);
                    player_turn = 0;
                }

                // update the value displayed for the players hand
                update_player_value(aux_value, mcol);
                break;
            case 's':
                //'s' stops the player's turn
                player_turn = 0;
                break;
            default:
                // any other input is ignored
                break;
            }
        }
        //hide_dealer_hand(dealer_hand);
        //update_player_hand(player_hand, mcol);

        //revealing the dealer's hidden card
        //and displaying the dealer's hand value
        update_dealer_hand(dealer_hand);
        aux_value=hand_value(dealer_hand);
        update_dealer_value(aux_value,mcol);

        //starting the dealer's turn
        dealer_turn=1;

        playing = 0;
    }
    getch();
    endwin();
    return 0;
}
