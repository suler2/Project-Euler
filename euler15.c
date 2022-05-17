#include <stdio.h>

#define SIZE 2

long path(int a, int b) {
    if (a == 0 || b == 0)
        return 1;
    else
        return path(a, b - 1) + path(a - 1, b);
}

int main() {
    int size = SIZE;
    int memo[SIZE+1][SIZE+1];
    for (int i = 0; i < SIZE+1; i++) {
        for (int j = 0; j < SIZE+1; j++) {
            memo[i][j] = 0;
        }
    }
    long res = path(size, size, memo);
    printf("%ld\n", res);
    return 0;
}
