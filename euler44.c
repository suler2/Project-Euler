#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

bool pentagonal(int n);
int formula(int n);

int main() {
    
    return 0;
}

int formula(int n) {
    return (int) (n * (3 * n - 1)) / 2;
}

bool pentagonal(int n) {
    double number = (sqrt(24 * n + 1) + 1) / 6;
    return ceilf(number) == number;
}
