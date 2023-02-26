#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "deck_operations.h"

void initialize_deck(int *deck)
{
    int i;
    for (i = 1; i <= 52; i++)
    {
        deck[i] = 0;
    }
}

int draw_card(int *deck)
{
    int card;
    time_t seed;
    time(&seed);
    srand(seed);
    card = rand() % 52 + 1;
    while (deck[card] == 1)
    {
        card = rand() % 52 + 1;
    }
    deck[card] = 1;
    return card;
}

char card_translation(int card_number)
{
    int remaining;
    remaining = card_number % 13;
    if (remaining >= 1 && remaining <= 8)
    {
        return (char)('0' + remaining + 1);
    }
    if (remaining == 0)
        return 'A';
    if (remaining == 10)
        return 'J';
    if (remaining == 11)
        return 'Q';
    if (remaining == 12)
        return 'K';
    if (remaining == 9)
        return 'T';
}

int card_value(int *current_total_value, char card)
{
    int i;
    for (i = 2; i <= 8; i++)
    {
        if (card == (char)('0' + i)) *current_total_value+=i;
    }
    
}