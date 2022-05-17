#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int preberiR(char *roman) {
    int st = 0;
    return st;
}

int main() {
    FILE *f = malloc(sizeof(FILE));
    f = fopen("euler89.txt", "r");
    char *roman = calloc(20, sizeof(char));
    char dump;
    while(fscanf(f, "%s", roman) != EOF) {
        int st = preberiR(roman);
        
    }
    fclose(f);
    return 0;
}
