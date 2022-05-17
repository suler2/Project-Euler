#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int matrix[80][80];
int new[80][80];

void input();
int findPath(int x, int y);

int main() {
    input();
    int min = 0;
    min = findPath(0, 0);
    printf("%d\n", min);
    return 0;
}

void input() {
    FILE *f = fopen("euler81.txt", "r");
    FILE *fw = fopen("euler81.out", "w+");
    char *s = calloc(40000, sizeof(char));
    printf("\n");
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

int findPath(int x, int y) {
    int sum = 0;
    int sum1 = 0;
    int sum2 = 0;
    if(x == 79 && y == 79) {
        new[y][x] = matrix[y][x];
//        return matrix[y][x];
    }
    else if (x == 79 && y < 79) {
        for (int i = y; i < 80; i++) {
            if(new[i][x] > 0) {
                sum += new[i][x];
                break;
            }
            sum += matrix[i][x];
        }
        new[y][x] = sum;
    }
    else if (x < 79 && y == 79) {
        for (int i = x; i < 80; i++) {
            if(new[y][i] > 0) {
                sum += new[y][i];
                break;
            }
            sum += matrix[y][i];
        }
        new[y][x] = sum;
    }
    else {
        if(new[y][x + 1] > 0)
            sum1 = matrix[y][x] + new[y][x + 1];
        else
            sum1 = matrix[y][x] + findPath(x + 1, y);
        if(new[y + 1][x] > 0)
            sum2 = matrix[y][x] + new[y + 1][x];
        else
            sum2 = matrix[y][x] + findPath(x, y + 1);
        if(sum1 < sum2) new[y][x] += sum1;
        else new[y][x] += sum2;
    }
    
    return new[y][x];
}
