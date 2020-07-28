#include <stdio.h>
#include <stdlib.>
#include "periodic_table.h"
#include "helper_functions.h"

#define MAX_ELEMENTS_IN_PERIODIC_TABLE 188
#define MAX_VALUE_LENGTH 1000

Periodic_Table* read_in_periodic_table(char *filename) {
    
    /* Setup Periodic Table to hold contents */
    Periodic_Table *pt;
    pt->elements = (Element *) malloc(sizeof(Element) * MAX_ELEMENTS_IN_PERIODIC_TABLE);

    /* Open the File, reading contents line by line and 
     * placing them into pt->elements */
    FILE *fp;
    char line[MAX_VALUE_LENGTH];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file; please make sure file exists");
        exit(1);
    }

    while (fgets(line, MAX_VALUE_LENGTH, fp) != NULL) {
        char delimiter  = ',';
        char **split_result = parse_string(line = &delimiter);
        
        // each item is in the correct location
        int atomic_number = (int) *split_result[0];
        Element e = {atomic_number, split_result[1], 
            split_result[2], split_result[3]};
        pt->elements[atomic_number] = e;
    }
    fclose(fp);
    return pt;
}

void print_periodic_table(Periodic_Table *pt) {
}

void get_information_for_element(Periodic_Table *pt, int atomic_number) {
}

void edit_periodic_table(Periodic_Table *pt, int atomic_number) {
}

void add_new_element_to_periodic_table(Periodic_Table *pt, Element e) {
}

void save_periodic_table_to_file(Periodic_Table *pt){
}

