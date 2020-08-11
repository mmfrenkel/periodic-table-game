#include <stdio.h>
#include <stdlib.h>
#include "periodic_table.h"
#include "helper_functions.h"

/* User should provide 1 item; second item should be \n */
#define USER_SUBMISSION_SIZE 2

int main(int argc, char *argv[]) {

	printf("\n-------*- PERIODIC TABLE GAME -*------\n");

	int keep_going = 1;
	char user_submission[USER_SUBMISSION_SIZE];
	char *filename = argv[1];

	/* read in the existing periodic table from file; changes
	 *  will be in memory until user quits */
	Periodic_Table *periodic_table = read_in_periodic_table(filename);

	while (keep_going) {
		printf("\n----------------------------------------------\n");
		printf("Please select an option from below:\n");
		printf("*---------------------------------*\n");
		printf(" 1. See All Saved Elements\n");
		printf(" 2. Edit Content of Element\n");
		printf(" 3. Add A New Element, by Atomic Number\n");
		printf(" 4. Save Edits to File\n");
		printf(" 5. Exit Program\n");
		printf("----------------------------------------------\n");

		scanf("\n"); /* To Do: Solve Need for This */
		fgets(user_submission, USER_SUBMISSION_SIZE, stdin);
		int user_selection = strtol(user_submission, NULL, 10);

		switch (user_selection) {
		case 1:
			print_periodic_table(periodic_table);
			break;
		case 2:
			edit_periodic_table(periodic_table);
			print_periodic_table(periodic_table);
			break;
		case 3:
			add_new_element_to_periodic_table(periodic_table);
			break;
		case 4:
			save_periodic_table_to_file(periodic_table, filename);
			break;
		case 5:
			save_periodic_table_to_file(periodic_table, filename);
			keep_going = 0;
			break;
		}
	}
	printf("Exiting Program...\n");
	free_periodic_table(periodic_table);
	return 0;
}

