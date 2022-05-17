#include <stdio.h>
#include <stdlib.h>

int grid[100][50];

void readGrid() {
    char *c = malloc(50 * sizeof(int));
    for (int i = 0; i < 100; i++) {
        scanf("%s", c);
        for (int j = 0; j < 50; j++) {
            grid[i][j] = c[j] - '0';
        }
    }
    free(c);
}

long first10(int min, int max, int carry) {
    long sum = 0;
    for (int i = 0; i < 100; i++) {
        long current = 0;
        for (int j = min; j < max; j++) {
            current = 10 * current + grid[i][j];
        }
        sum = sum + current;
    }
    sum = sum + carry;
    return sum;
}

int main() {
    long sum = 0;
    long carry = 0;
    readGrid();
    for (int i = 10; i < 50; i = i + 10) {
        carry = sum / 10000000000;
        sum = first10(i, i + 10, carry);
        
    }  
    carry = sum / 10000000000;
    sum = first10(0, 10, carry);
    printf("%ld\n", sum);
    return 0;
}
