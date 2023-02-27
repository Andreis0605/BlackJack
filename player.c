#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deck_operations.h"

void player_add_in_hand(char *player_hand, char card)
{
    int n;
    n = strlen(player_hand);
    player_hand[n] = card;
    player_hand[n + 1] = '\n';
}

