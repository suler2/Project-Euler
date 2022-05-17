#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long getLim(int base, int exp) {
    if(exp == 0) return 1;
    else return 2 * getLim(base, exp - 1);
}

int main() {
    long lim = getLim(2, 30);
    for (int i = 1; i < lim) {
        
    }
    printf("%ld\n", lim);
    return 0;
}
