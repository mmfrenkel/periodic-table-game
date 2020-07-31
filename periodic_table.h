
typedef struct element Element;

typedef struct periodic_tablePeriodic_Table;

Element * create_element_from_line(char *line, char delimiter);

void print_element(Element *el);

void print_periodic_table(Periodic_Table *pt);

void get_information_for_element(Periodic_Table *pt, int atomic_number);

void edit_periodic_table(Periodic_Table *pt, int atomic_number);

void add_new_element_to_periodic_table(Periodic_Table *pt, Element e);

void save_periodic_table_to_file(Periodic_Table *pt);

