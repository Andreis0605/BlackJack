#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "deck_operations.h"
#include "interface.h"

int main()
{
    int k, deck[53], i;
    char card;
    initialize_deck(deck);
    k=draw_card(deck);
    card=card_translation(k);
    printf("%c\n",card);
    return 0;
}
