#include <stdio.h>

#define MAXI 4000000

int fib(int a, int b);

int main () {
    printf ("%d\n", fib(1, 2));
    return 0;
}

int fib (int a, int b) {
    if (a > MAXI || b > MAXI) {
        return 0;
    }
    else if (a > b && (a % 2) == 0) {
        return a + fib (a, a + b);
    }
    else if (a > b) {
        return fib (a, a + b);
    }
    else if (b > a && (b % 2) == 0) {
        return b + fib (a + b, b);
    }
    else if (b > a) {
        return fib (a + b, b);
    }
}
