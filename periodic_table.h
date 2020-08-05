
typedef struct element Element;

typedef struct periodic_table Periodic_Table;

Periodic_Table * read_in_periodic_table(char *filename);

Element * create_element_from_line(char *line, char delimiter);

Element * create_new_element(int atomic_number, char *name, char *classification, char *properties);

void print_element(Element *el);

void print_periodic_table(Periodic_Table *pt);

void get_information_for_element(Periodic_Table *pt, int atomic_number);

void edit_periodic_table(Periodic_Table *pt);

void add_new_element_to_periodic_table(Periodic_Table *pt);

void save_periodic_table_to_file(Periodic_Table *pt, char *filename);

void free_periodic_table(Periodic_Table *pt);

