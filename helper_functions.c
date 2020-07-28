#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* Takes a string (array of chars) and a deliminiter (array of chars)
 * and creates a list of delimited values (pointer to a list of char 
 * pointers */
char** parse_string(char *string, char *deliminter) {
    
    char **to_return = malloc(sizeof(char *) * 4);
    int i = 0;

    char *token = strtok(string, ",");
    while (token != NULL) {
        /* or could use strdup(token); */
        to_return[current_index] = malloc(sizeof(char) * strlen(token)) ;
        strcpy(to_return[i++], token);
        token = strtok(NULL, " ");
    }
    return to_return;
}

