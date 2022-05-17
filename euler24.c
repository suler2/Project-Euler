#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIM 1000000

long factorial(int n);
long digits(long n, long fac, int lim, bool* used);

int main() {
    long *memo_fac = malloc(10 * sizeof(long));
    for (int i = 0; i < 10; i++)
        memo_fac[i] = factorial(9 - i);
    long* p = calloc(10, sizeof(long));
    bool *used = (bool*)calloc(10, sizeof(bool));
    int lim = LIM;
    for (int i = 0; i < 10; i++) {
        p[i] = digits(0, memo_fac[i], lim, used);
        lim = lim - p[i] * memo_fac[i];
    }
    printf("\n");

    return 0;
}

long factorial(int n) {
    if(n == 0) return 1;
    if(n == 1) return 1;
    else return n * factorial(n - 1);
}

long digits(long n, long fac, int lim, bool *used) {
    if(n * fac >= lim || n >= 10) {
        int res = 0;
        int lim = n;
        for (int i = 0; i < lim && i < 10; i++) {
            if(used[i]) {res++; lim++;}
        }
        res = res + n - 1;
        used[res] = true;
        printf("%d", res);
        return n - 1;
    }
    else {
        return digits(n + 1, fac, lim, used);
    }
}
