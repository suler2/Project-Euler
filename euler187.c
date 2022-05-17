#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define LIM 100000000

/*
2 -> 2
3 -> 3
4 -> 2, 2, 4
5 -> 5
6 -> 2, 3, 6
7 -> 7
8 -> 2, 2, 2, 3
*/

bool is_prime(int n) {
    if(n == 2) return true;
    else if (n % 2 == 0) return false;
    else {
        for (int i = 3; i <= (int) ceil(sqrt(n)); i += 2) {
            if(n % i == 0) return false;
        }
        return true;
    }
}



int main() {
    int *primes = calloc(LIM, sizeof(int));
    primes[0] = 2;
    int index = 1;
    for (int i = 3; i <= LIM / 100; i += 2) {
        if(is_prime(i)) primes[index++] = i;
    }
    int count = 0;
    printf("%d\n", count);
    free(primes);
    return 0;
}
