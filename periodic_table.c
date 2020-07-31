#include <stdio.h>
#include <stdlib.h>
#include "periodic_table.h"
#include "helper_functions.h"

/* There are only 118 elements in the periodic table */
#define MAX_ELEMENTS_IN_PERIODIC_TABLE 119
#define MAX_VALUE_LENGTH 1000


struct element {
    int atomic_number;
    char *name;
    char *classification;
    char *properties;
};

/* Table must hold max elements + 1 in order for elements to be kept at 
 * indicies matching their atomic number */
struct periodic_table {
    Element *elements[MAX_ELEMENTS_IN_PERIODIC_TABLE + 1];
};


Periodic_Table* read_in_periodic_table(char *filename) {
    
    /* Setup Periodic Table; initialize all elements to have value of 0 */
    Periodic_Table *pt = (Periodic_Table *) malloc(sizeof(Periodic_Table));
    for (int i = 0; i < MAX_ELEMENTS_IN_PERIODIC_TABLE + 1; i++) {
        *(pt->elements[i]) = NULL;
    }

    /* Open the File, reading contents line by line and 
     * placing them into pt->elements */
    FILE *fp;
    char line[MAX_VALUE_LENGTH];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file; please make sure file exists");
        free(pt);
        exit(1);
    }

    while (fgets(line, MAX_VALUE_LENGTH, fp) != NULL) {
        char delimiter  = ',';
        Element *e = create_element_from_line(line, deliminiter);
        pt->elements[e->atomic_number] = e;
    }
    fclose(fp);
    return pt;
}


/* Creates a new Element in memory, using contents found in a 
 * file line. Returns pointer to the Element. */
Element * create_element_from_line(char *line, char delimiter){
    /* Parse the line to get element information */
    char **split_result = parse_string(line, &deliminter);

    /* Create a new element */
    Element *e = (Element *) malloc(sizeof(Element));
    
    /* Insert values into element */
    int atomic_number = atoi(split_result[0]);
    e->atomic_number = atomic_number;
    e->name = split_result[1];
    e->classification = split_result[2];
    e->properties = split_result[3];

    print_element(e);
    return e;
}


/* Prints out Specified Element */
void print_element(Element *el) {
    printf("\n%s\n", el->name);
    printf("---------------\n");
    printf("Atomic Number: %s\n", el->atomic_number);
    printf("Classification: %s\n", el->classification);
    printf("Properties: %s\n", el->classification);
}

/* Prints out all Elements in Periodic Table */
void print_periodic_table(Periodic_Table *pt) {
    
    printf("PERIODIC TABLE\n");
    printf("-------------------\n");
    for (int i = 0; i < MAX_ELEMENTS_IN_PERIODIC_TABLE + 1; i++){
        print_element(pt->elements[i]);
    }
}

void get_information_for_element(Periodic_Table *pt, int atomic_number) {
}

void edit_periodic_table(Periodic_Table *pt, int atomic_number) {
}

void add_new_element_to_periodic_table(Periodic_Table *pt, Element e) {
}

void save_periodic_table_to_file(Periodic_Table *pt){
}

