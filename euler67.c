#include <stdio.h>
#include <stdlib.h>

int** build();
int findMax(int** a, int i, int j);

int main() {
    
    int** a = build();
    int max = findMax(a, 99, 0);
    printf("%d\n", max);
    free(a);
    return 0;
}

int** build() {
    FILE *f = fopen("euler67.txt", "r");
    int** a = (int**)malloc(100 * sizeof(int*));
    int st = 0;
    for (int i = 1; i <= 100; i++) {
        *(a + i - 1) = (int*)malloc(i * sizeof(int));
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j <= i; j++) {
            fscanf(f, "%d", &st);
            a[i][j] = st;
        }
    }
    fclose(f);
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

/*
int findMax(int** a) {
    for (int i = 99; i > 0; i--) {
        for (int j = 0; j <= i; j++) {
            if(a[i][j] > a[i][j + 1])
                a[i - 1][j] = a[i - 1][j] + a[i][j];
            else a[i - 1][j] = a[i - 1][j] + a[i][j + 1];
        }
    }
    return a[0][0];
}
*/
