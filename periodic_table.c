#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "periodic_table.h"
#include "helper_functions.h"

/* There are only 118 elements in the periodic table */
#define MAX_ELEMENTS_IN_PERIODIC_TABLE 118
#define MAX_VALUE_LENGTH 1000
#define NUM_ITEMS_IN_ELEMENT 4

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

/* Reads in periodic table elements from a file and creates
 * a new Periodic Table, containing a reference to an array of Elements */
Periodic_Table* read_in_periodic_table(char *filename) {
    
    /* Setup Periodic Table; initialize all elements to have value of NULL */
    Periodic_Table *pt = (Periodic_Table *) malloc(sizeof(Periodic_Table));
    for (int i = 0; i <= MAX_ELEMENTS_IN_PERIODIC_TABLE + 1; i++) {
        pt->elements[i] = NULL;    
    }

    /* Open the File, reading contents line by line and * placing them into pt->elements */
    FILE *fp;
    char line[MAX_VALUE_LENGTH];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file; please make sure file exists");
        free(pt);
        exit(1);
    }

    while (fgets(line, MAX_VALUE_LENGTH, fp) != NULL) {
        char delimiter[]  = {','};
        Element *e = create_element_from_line(line, delimiter);
        pt->elements[e->atomic_number] = e;
    }
    fclose(fp);
    return pt;
}


/* Creates a new Element in memory, using contents found in a 
 * file line. Returns pointer to the Element. */
Element * create_element_from_line(char *line, char *delimiter){
    /* Parse the line to get element information */
    char **split_result = parse_string(line, delimiter, NUM_ITEMS_IN_ELEMENT);

    /* Create a new element */
    Element *e = create_new_element(atoi(split_result[0]), split_result[1], 
                split_result[2], split_result[3]);
    print_element(e);
    return e;
}

/* Create new Element in Heap memory; Address of new Element returned */
Element * create_new_element(int atomic_number, char *name, char *classification, char *properties) {
    Element *e = (Element *) malloc(sizeof(Element));
    e->atomic_number = atomic_number;
    
    e->name = (char *) malloc(sizeof(char) * strlen(name));
    e->name = name;

    e->classification = (char *) malloc(sizeof(char) * strlen(classification));
    e->classification = classification;

    e->properties = (char *) malloc(sizeof(char) * strlen(properties));
    e->properties = properties;

    return e;
}


/* Prints out Specified Element */
void print_element(Element *el) {
    printf("\n%s\n", el->name);
    printf("---------------\n");
    printf("Atomic Number: %d\n", el->atomic_number);
    printf("Classification: %s\n", el->classification);
    printf("Properties: %s\n", el->properties);
}

/* Prints out all Elements in Periodic Table */
void print_periodic_table(Periodic_Table *pt) {
    
    printf("PERIODIC TABLE\n");
    printf("-------------------\n");

    int i;
    for (i = 0; i < MAX_ELEMENTS_IN_PERIODIC_TABLE + 1; i++){
        
        /* Don't attempt to print elements that don't yet exist */
        if (pt->elements[i] != NULL) {
            print_element(pt->elements[i]);
        }
    }
}

/* Get information for an Element specified by its atomic number */
void get_information_for_element(Periodic_Table *pt, int atomic_number) {
    Element *element_ptr = pt->elements[atomic_number];
    print_element(element_ptr);
}

/* Edit Aspect of Periodic Table Element, by atomic number */
void edit_periodic_table(Periodic_Table *pt) {
    /* Ask for user input */
    printf("Please provide the atomic number of the element to edit: ");
    int atomic_number;
    scanf("%d", &atomic_number);
    Element *element_ptr = pt->elements[atomic_number];
    
    printf("Select the action you would like:\n");
    printf(" (1) Edit Name\n");
    printf(" (2) Edit Classification\n");
    printf(" (3) Edit Properties\n");
    printf(" (4) Continue without Editing\n");

    int user_selection; 
    char user_submission[MAX_VALUE_LENGTH / NUM_ITEMS_IN_ELEMENT];
    scanf("%d", &user_selection);

    switch(user_selection) {
        case 1:
            printf("Provide New Name For Element: ");
            scanf("%s", user_submission);
            element_ptr->name = user_submission;
        case 2:
            printf("Provide New Classification For Element: ");
            scanf("%s", user_submission);
            element_ptr->classification = user_submission;
        case 3:
            printf("Provide New Properties Description for Element: ");
            scanf("%s", user_submission);
            element_ptr->properties = user_submission;
    }

}

/* Function used to add new element to periodic table */
void add_new_element_to_periodic_table(Periodic_Table *pt) {
    
    int atomic_number;
    char name[MAX_VALUE_LENGTH / NUM_ITEMS_IN_ELEMENT];
    char classification[MAX_VALUE_LENGTH / NUM_ITEMS_IN_ELEMENT];
    char properties[MAX_VALUE_LENGTH / NUM_ITEMS_IN_ELEMENT];

    printf("Please submit an atomic number: ");
    scanf("%d", &atomic_number);

    if (atomic_number < 1 || atomic_number > 188) {
        printf("Sorry, your selection of atomic number is outside the valid range: 0 - 188\n");
        return;
    }
    else if (pt->elements[atomic_number] != NULL) {
        printf("Sorry, your selection of atomic number is already taken!\n");
        print_element(pt->elements[atomic_number]);
        return;
    }
    
    printf("Please submit a classification: ");
    scanf("%s", classification);
    printf("Please submit a description for this element: ");
    scanf("%s", properties);

    Element *e = create_new_element(atomic_number, name, classification, properties);
    pt->elements[atomic_number] = e;
}

/* Saves periodic table to a file, maintaining atomic_number order. Replaces old file */
void save_periodic_table_to_file(Periodic_Table *pt, char *filename){
    FILE *fp = fopen(filename, "w");
    Element **elements = pt->elements;
    int i; 

    for (i = 1; i < MAX_ELEMENTS_IN_PERIODIC_TABLE + 1; i++) {
        if (elements[i] != NULL) {
            Element *e = elements[i];
            fprintf(fp, "%d,%s,%s,%s", e->atomic_number, e->name, e->classification, e->properties);
        }
    }
    fclose(fp);
}

/* Free all memory associated with Periodic Table */
void free_periodic_table(Periodic_Table *pt) {
    /* get array of pointers to elements to be deleted */
    Element **ptr_arr = pt->elements;
 
    int i;
    for (i = 0; i < MAX_ELEMENTS_IN_PERIODIC_TABLE + 1; i++) {
        free(ptr_arr[i]);
    }
    free(pt);
}   

