#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void solve(char **sudoku);

int main() {
    FILE *f = malloc(sizeof(FILE));
    f = fopen("euler96.txt", "r");
    char **sudoku = calloc(100, sizeof(char*));
    for (int i = 0; i < 9; i++) sudoku[i] = calloc(100, sizeof(char));
    int ix = 0;
    while(fgets(line, 100, f)) {
        if(ix % 10 == 0) {
            solve(sudoku);
        }
        else {
            sudoku[(ix % 10) - 1] = line;
        }
    }
    for (int i = 0; i < 9; i++) free(sudoku[i]);
    free(sudoku);
    fclose(f);
    return 0;
}

void solve(char **sudoku) {
    
}
