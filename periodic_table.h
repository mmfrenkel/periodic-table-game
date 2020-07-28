
typedef struct element {
    int atomic_number;
    char name[100];
    char classification[100];
    char properties[100];
} Element;


typedef struct periodic_table {
    Element *elements;
} Periodic_Table;

void print_periodic_table(Periodic_Table *pt);

void get_information_for_element(Periodic_Table *pt, int atomic_number);

void edit_periodic_table(Periodic_Table *pt, int atomic_number);

void add_new_element_to_periodic_table(Periodic_Table *pt, Element e);

void save_periodic_table_to_file(Periodic_Table *pt);

