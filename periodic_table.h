
typedef struct element {
    int atomic_number;
    char name[100];
    char classification[100];
    char properties[100];
} Element;


typedef struct periodic_table {
    Element *elements;
} Periodic_Table;

