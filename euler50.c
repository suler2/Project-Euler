#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define LIM 1000000

int getPrimes(int *sieve);
bool check_prime(int n);
int findLargestSum(int **primes, int n, int len);

int main() {
    int *sieve = (int*)calloc(LIM, sizeof(int));
    int len = getPrimes(sieve);
    int **primes = malloc(len * sizeof(int*));
    for (int i = 0; i < len; i++) {
        primes[i] = calloc(2, sizeof(int));
        primes[i][0] = sieve[i];
        primes[i][1] = -1;
    }
    free(sieve);
    int n = 0;
    int max = 0;
    int maxnr = 0;
    primes[0][1] = 0;
    primes[1][1] = 0;
    for (int i = 2; i < len; i++) {
        primes[i][1] = findLargestSum(primes, primes[i][0], i);
        if(primes[i][1] > max) {
            max = primes[i][1];
            maxnr = primes[i][0];
        }
    }
    
    printf("%d %d\n", maxnr, max);
    free(primes);
    return 0;
}

int findLargestSum(int **primes, int n, int len) {
    int sum = 0;
    int lower = 0;
    int upper = 0;
    while (sum != n) {
        if (sum < n) {
            sum += primes[upper][0];
            upper++;
        }
        else if (sum > n) {
            sum = sum - primes[lower][0];
            lower++;
        }
    }
    primes[len][1] = sum;
    return upper - lower;
}

int getPrimes(int *sieve) {
    sieve[0] = 2;
    sieve[1] = 3;
    int counter = 2;
    for (int i = 5; i < LIM; i += 2) {
        if(check_prime(i)) {
            sieve[counter] = i;
            counter++;
        }
    }
    return counter;
}

bool check_prime(int n) {
    if((n % 2) == 0) return false;
    for (int i = 3; i <= (int)ceil(sqrt(n)); i += 2)
        if((n % i) == 0) return false;
    return true;
}
