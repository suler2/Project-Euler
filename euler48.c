#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MODULO 10000000000
#define LIM 1000

int main() {
    long result = 0;
    for (int i = 1; i <= LIM; i++) {
        long tmp = i;
        for (int j = 1; j < i; j++) {
            tmp *= i;
            tmp = tmp % MODULO;
        }
        result += tmp;
        result = result % MODULO;
    }
    printf("%ld\n", result);
    return 0;
}
