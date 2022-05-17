#include <stdio.h>



int sum (int n) {
    return (n * ( n + 1)) / 2 ;
}

int main() {
    long a, b;
    a = b = 0;
    for (int i = 1; i <= 100; i++) {
        a = a + i * i;
        b = b + i;
    }
    printf ("%ld\n", b * b - a);
    return 0;
}
