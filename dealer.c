#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deck_operations.h"

void dealer_add_in_hand(char *dealer_hand, char card)
{
    int n;
    n = strlen(dealer_hand);
    dealer_hand[n] = card;
    dealer_hand[n + 1] = '\n';

}