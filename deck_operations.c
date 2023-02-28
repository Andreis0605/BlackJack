#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deck_operations.h"

int comp(const void *a, const void *b)
{
    char *x, *y;
    x = (char *)a;
    y = (char *)b;
    return (int)*y - *x;
}

int add_aces_value(int value, int aces_number)
{
    int i, aces_value, max_value;
    max_value = value;
    aces_value = aces_number;
    for (i = 0; i <= aces_number; i++)
    {
        if (value + aces_value > max_value && value + aces_value <= 21)
        {
            max_value = value + aces_value;
        }
        aces_value += 10;
    }
    if (max_value == value)
        value += aces_number;
    else
        value = max_value;
    return value;
}

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
        if (card == (char)('0' + i))
            *current_total_value += i;
    }
    if (card == 'J')
        *current_total_value += 10;
    if (card == 'Q')
        *current_total_value += 10;
    if (card == 'K')
        *current_total_value += 10;
    if (card == 'A')
    {
        if (*current_total_value + 10 > 21)
            *current_total_value += 1;
        else
            *current_total_value += 11;
    }
    if (card == 'T')
        *current_total_value += 10;
}

int hand_value(char *player_hand)
{
    int value = 0, i, j, count_A = 0;
    char *copy_player_hand, aux_char;
    strcpy(copy_player_hand, player_hand);

    // sorting copy_player_hand
    qsort(copy_player_hand, strlen(copy_player_hand), sizeof(char), comp);

    for (i = 0; i < strlen(copy_player_hand); i++)
    {
        if (copy_player_hand[i] == 'A')
        {
            count_A++;
        }
        else
        {
            if (copy_player_hand[i] >= '2' && copy_player_hand[i] <= '9')
            {
                value += (int)(copy_player_hand[i] - '0');
            }
            if (copy_player_hand[i] == 'J')
                value += 10;
            if (copy_player_hand[i] == 'Q')
                value += 10;
            if (copy_player_hand[i] == 'K')
                value += 10;
            if (copy_player_hand[i] == 'T')
                value += 10;
        }
    }
    value = add_aces_value(value, count_A);
    return value;
}
