#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int stImen(char *name, char locilo);
char** buildTable(char* name, int len, char locilo);
char** sortTable(char** table, int len);
long sumTable(char** table, int len);

int main() {
    char* name = (char*)calloc(47000, sizeof(char));
    scanf ("%s", name);
    int len = stImen(name, ',');
    char **table = buildTable(name, len, ',');
    long sum = sumTable(table, len);
    printf("%ld\n", sum);
    /*
//    printf("%s\n", name);
//    printf("%d\n", len);
    for (int i = 0; i < len; i++) {
        printf("%s\n", table[i]);
    }
    */
    free(name);
    free(table);
    return 0;
}

int stImen(char *name, char locilo) {
    int count = 0;
    int i = 0;
    while(name[i] != '\0') {
        if(name[i] == locilo) count++;
    i++;
    }
    return count + 1;
}

char** buildTable(char* name, int len, char locilo) {
    char** table = (char**)malloc(len * sizeof(char*));
    for (int i = 0; i < len; i++) {
        table[i] = calloc(50, sizeof(char));
    }
    int i = 0;
    int besede = 0;
    int znaki = 0;
    while(1) {
        if(name[i] == locilo) {
//            table[besede] = realloc(table[besede], (znaki + 1) * sizeof(char));
            table = sortTable(table, besede + 1);
            besede++;
            znaki = 0;
        }
        if(name[i] == '\0') {
            table = sortTable(table, besede + 1);
            break;
        }
        else if(name[i] >= 'A' && name[i] <= 'Z') {
            table[besede][znaki] = name[i];
            znaki++;
        }
        i++;
    }
    return table;
}

char** sortTable(char** table, int len) {
    bool sorted = false;
    for(int i = len - 2; i >= 0; i--) {
        for (int j = 0; j < 50; j++) {
            if(table[i][j] > table[i + 1][j] || table[i + 1][j] == '\0') {
                char* p = (char*)calloc(50, sizeof(char));
                strcpy(p, table[i]);
                strcpy(table[i], table[i + 1]);
                strcpy(table[i + 1], p);
                free(p);
                break;
            }
            else if(table[i][j] < table[i + 1][j] || table[i][j] == '\0') {
                sorted = !sorted;
                break;
            }
            else {}
        }
        if(sorted)break;
    }
    return table;
}

long sumTable(char** table, int len) {
    long sum = 0;
    for (int i = 0; i < len; i++) {
        int letVal = 0;
        for (int j = 0; table[i][j] != '\0'; j++) {
            letVal = letVal + (table[i][j] - 'A' + 1);
        }
        sum = sum + letVal * (i + 1);
    }
    return sum;
}
