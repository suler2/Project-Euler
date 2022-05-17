#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int formula(int n, int a, int b) {
    return n * n + a * n + b;
}

bool prime(int n) {
    if(n < 2) return 0;
    else if (n == 2) return 1;
    else if (n % 2 == 0) return 0;
    else {
        for (int i = 3; i <= (int) ceil(sqrt(n)); i += 2) {
            if(n % i == 0) return false;
        }
    }
    return true;
}

int stPrastevil(int a, int b, int n) {
/*
    int st = formula(n, a, b);
    if(!prime(st)) return 0;
    else return 1 + stPrastevil(a, b, n + 1);
*/  
    int st = formula(n, a, b);
    n++;
    while(prime(st)) {
        st = formula(n, a, b);
        n++;
    } 
    return n;
}

int findMax(int** combs, int len) {
    int maxLen = 0;
    int index = 0;
    for (int i = 0; i < len; i++) {
        int current = stPrastevil(combs[i][0], combs[i][1], 3);
        if(maxLen < current) {
            maxLen = current;
            index = i;
        }
    }
    return combs[index][0] * combs[index][1];
}

int main() {
    int len = 0;
    int **combs = calloc(1000000, sizeof(int*));
    for (int i = 0; i < 1000000; i++) {
        combs[i] = calloc(2, sizeof(int));
    }
    for (int b = 3; b <= 1000; b++) {
        if(prime(b)) {
            for (int a = -999; a < 1000; a++) {
                int res = formula(1, a, b);
                int res2 = formula(2, a, b);
                int res3 = formula(3, a, b);
                if(prime(res) && prime(res2) && prime(res3)) {
                    combs[len][0] = a;
                    combs[len][1] = b;
                    len++;
                }
            }
        }
    }
    combs = realloc(combs, len * sizeof(int*));
    int produkt = findMax(combs, len);
    printf("%d\n", produkt);
    free(combs);
    return 0;
}
