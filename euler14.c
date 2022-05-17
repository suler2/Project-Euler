#include <stdio.h>
#include <stdlib.h>

int collatz (long n, int res[]) {
    if(n == 1) {
        return 1;
    }
    else if (n < 1000000 && res[n] != 0) {
        return res[n];
    }
    else if ((n % 2) == 0) {
        return 1 + collatz(n / 2, res);
    }
    else {
        return 2 + collatz((3 * n + 1)/2, res);
    }
}

int main() {
    int max = 0;
    int n = 0;
    int *res = malloc(sizeof(int) * 1000000);
    for (int i = 0; i < 1000000; i++) res[i] = 0;
    for (long i = 2; i < 999999; i++) {
        int count = 0;
        count = collatz(i, res);
        res[i] = count;
        if (count > max) {
            max = count;
            n = i;
        }
    } 
    printf("%d\n", n);
    return 0;
}
