#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool primes[50000];

void sieve();
bool prime(int n);

int main() {
    sieve();
    int *set = calloc(5 * sizeof(int));
    for (int i = 2; i < 50000; i++) {
        if(primes[i]) {
            
        }
    }
    return 0;
}

void sieve() {
    for (int i = 0; i < 50000; i++) primes[i] = false;
    primes[2] = true;
    primes[3] = true;
    for (int i = 6; i < 50000; i += 6) {
        if(prime(i - 1)) primes[i - 1] = true;
        else if (prime(i + 1)) primes[i + 1] = true;
    }
}

bool prime(int n) {
    if ((n % 2) == 0) return false;
    for (int i = 3; i <= (int) ceil(sqrt(n)); i += 2)
        if((n % i) == 0) return false;
    return true;
}
