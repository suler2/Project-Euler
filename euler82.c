#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int matrix[80][80];

void input();
int findPath(int x, int y, int **new, int dir);

int main() {
    input();
    int min = INT_MAX;
    for (int i = 0; i < 80; i++) {
        int current = 0;
        int **new = (int**)malloc(80 * sizeof(int*));
        for (int j = 0; j < 80; j++)
            new[j] = (int*)calloc(80, sizeof(int));
        current = matrix[i][0] + findPath(1, i, new, 2);
        if(current < min) min = current;
        free(new);
    }
    printf("%d\n", min);
    return 0;
}

void input() {
    FILE *f = fopen("euler81.txt", "r");
    FILE *fw = fopen("euler81.out", "w+");
    char *s = calloc(40000, sizeof(char));
    int vrstica = 0; 
    int stolpec = 0;
    int index = 0;
    int trenutno = 0;
    
    while(fgets(s, 40000, f)){
        index = 0;
        while(true) {
            if(s[index] == '\n') {
                matrix[vrstica][stolpec] = trenutno;
                trenutno = 0;
                stolpec = 0;
                break;
            }
            if(s[index] == ',') {
                matrix[vrstica][stolpec] = trenutno;
                trenutno = 0;
                stolpec++;
            }
            else trenutno = trenutno * 10 + s[index] - '0';
            index++;
        }
        vrstica++;
    }
    
    fclose(fw);
    fclose(f);
}

int findPath(int x, int y, int **new, int dir) {
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    if(x == 79) {
        new[y][x] = matrix[y][x];
    }
    else if(y == 0) {
        if(new[y][x + 1] > 0) sum1 = matrix[y][x] + new[y][x + 1];
        else sum1 = matrix[y][x] + findPath(x + 1, y, new);
//        if(new[y + 1][x] > 0) sum2 = matrix[y][x] + new[y + 1][x];
//        else sum2 = matrix[y][x] + findPath(x, y + 1, new);
        if(sum1 < sum2) new[y][x] = sum1;
        else new[y][x] = sum2;
    }
    else if(y == 79) {
        if(new[y][x + 1] > 0) sum1 = matrix[y][x] + new[y][x + 1];
        else sum1 = matrix[y][x] + findPath(x + 1, y, new);
//        if(new[y - 1][x] > 0) sum2 = matrix[y][x] + new[y - 1][x];
//        else sum2 = matrix[y][x] + findPath(x, y - 1, new);
        if(sum1 < sum2) new[y][x] = sum1;
        else new[y][x] = sum2;
    }
    else {
        if(new[y - 1][x] > 0) sum1 = matrix[y][x] + new[y - 1][x];
        else sum1 = matrix[y][x] + findPath(x, y - 1, new);
        if(new[y + 1][x] > 0) sum2 = matrix[y][x] + new[y + 1][x];
        else sum2 = matrix[y][x] + findPath(x, y + 1, new);
        if(new[y][x + 1] > 0) sum3 = matrix[y][x] + new[y][x + 1];
        else sum3 = matrix[y][x] + findPath(x + 1, y, new);
        if(sum1 < sum2 && sum1 < sum3) new[y][x] = sum1;
        else if(sum2 < sum1 && sum2 < sum3) new[y][x] = sum2;
        else if(sum3 < sum1 && sum3 < sum2) new[y][x] = sum3;
    }
    return new[y][x];
}
