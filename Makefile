CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -g 

periodic_table_game: helper_functions.o periodic_table.o

helper_functions.o: helper_functions.h

periodic_table.o: periodic_table.h

.PHONY: clean
clean:
	rm -rf main periodic_table_game *.o a.out

.PHONY: launch
launch: periodic_table_game
	./periodic_table_game elements.txt

