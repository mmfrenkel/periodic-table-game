#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* Takes a string (array of chars) and a deliminiter (single char)
 * and creates a list of delimited values (pointer to a list of char 
 * pointers */
char** parse_string(char *string, char delimiter, int max_results) {

    char **to_return = malloc(sizeof(char *) * max_results);
    int i = 0;

    char *token = strtok(string, &delimiter);

    while (token != NULL && i < max_results) {
        /* or could use strdup(token); */
        to_return[i] = malloc(sizeof(char) * strlen(token)) ;
        strcpy(to_return[i++], token);
        token = strtok(NULL, &delimiter);
    }
    return to_return;
}
 
/* Determines if a string is just whitespace */
int is_empty(char *s) {
    printf("%s", s);
    while (*s != '\0') {
        if (!isspace((unsigned char) *s)) {
            return 0;
        }
        s++;
    }
    return 1;
}

