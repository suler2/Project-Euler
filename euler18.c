#include <stdio.h>
#include <stdlib.h>

/*
DELUJOCA VERZIJA
*/

int** build();
int findMax(int** a, int i, int j);

int main() {
    int** a = build();
    int max = findMax(a, 14, 0);
    printf("%d\n", max);
    free(a);
    return 0;
}

int** build() {
    int** a = (int**)malloc(15 * sizeof(int*));
    int st = 0;
    for (int i = 1; i <= 15; i++) {
        *(a + i - 1) = (int*)malloc(i * sizeof(int));
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &st);
            a[i][j] = st;
        }
    }
    return a;
}

int findMax(int** a, int i, int j) {
    if(i == 0) {
        return a[i][j];
    }
    else {
        if(a[i][j] > a[i][j + 1])
            a[i - 1][j] = a[i - 1][j] + a[i][j];
        else a[i - 1][j] = a[i - 1][j] + a[i][j + 1];
        if(j < i) return findMax(a, i, j + 1);
        else return findMax(a, i - 1, 0);
    }
}
