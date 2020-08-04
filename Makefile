
periodic_table_game: main.c helper_functions.so periodic_table.so
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra main.c helper_functions.so periodic_table.so -o periodic_table_game

helper_functions.so: helper_functions.c helper_functions.h
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c helper_functions.c -o helper_functions.so

periodic_table.so: periodic_table.c periodic_table.h
	gcc -std=c11 -Wall -fmax-errors=1- -Wextra -c periodic_table.c -o periodic_table.so

launch: periodic_table_game
	./periodic_table_game

