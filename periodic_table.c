#include <stdio.h>
#include "periodic_table.h"

#define MAX_ELEMENTS_IN_PERIODIC_TABLE 188

Periodic_Table read_in_periodic_table() {
    Periodic_Table *pt;
    pt->elements = (Element *) malloc(sizeof(Element) * MAX_ELEMENTS_IN_PERIODIC_TABLE);
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

