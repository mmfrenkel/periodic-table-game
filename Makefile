CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -g 

periodic_table_game: helper_functions.so periodic_table.so

helper_functions.so: helper_functions.h

periodic_table.so: periodic_table.c periodic_table.h

.PHONY: clean
clean:
	rm -rf main *.o a.out

.PHONY: launch
launch: periodic_table_game
	./periodic_table_game elements.txt

