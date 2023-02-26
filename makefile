blackjack: game.o deck_operations.o interface.o
	gcc -Wall game.o deck_operations.o interface.o -o blackjack -lncurses

game.o: game.c
	gcc -c game.c -lncurses

deck_operations.o: deck_operations.c deck_operations.h
	gcc -c deck_operations.c -lncurses

interface.o: interface.c interface.h
	gcc -Wall -c interface.c -lncurses

clean:
	rm *.o