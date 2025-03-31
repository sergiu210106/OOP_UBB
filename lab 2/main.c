#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char * my_strchr( const char * str, char character ) {
    char *p = str;
    while (*p != '\0') {
        if (*p == character)
            return p;
        p++;
    }
    return NULL;
}

void find_all(const char *str, char character, int* positions, unsigned int cap, unsigned int *l){
    char *p = str;
    *l = 0;
    while (*p != '\0') {
        char *q = my_strchr(p, character);
        if (q != NULL && *l + 1 <= cap) {
            positions[(*l)++] = (int) (q - str);
        }
        else {
            break;
        }
        p = q + 1;
    }
}

int main() {
    char s[100];
    scanf("%s", s);

    unsigned int l = 0;
    int * positions = (int*) calloc(100, strlen(s));

    for (int i = 0; i < strlen(s);i ++)
        positions[i] = -1;

    find_all(s, 'e', positions, 100, &l);

    for (int i = 0; i < l; i++) {
        printf("%d ", positions[i]);
    }
    printf("\n%d\n", l);
    free(positions);
    return 0;
}