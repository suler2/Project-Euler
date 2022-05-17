#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define LIM 50000

int count;

int power(int base, int exp) {
    if(exp == 1) return base;
    else return base * power(base, exp - 1);
}

void combs(int *primes, int first, int second, int third) {
    int sum = power(primes[first], 2) + power(primes[second], 3) + 
              power(primes[third], 4);
//    printf("%d, %d, %d, %d\n", first, second, third, sum);
    if(!primes[first] || !primes[second] || !primes[third]) return;
    if(sum > LIM) return;
    count++;
    combs(primes, first + 1, second, third);
    combs(primes, first, second + 1, third);
    combs(primes, first, second, third + 1);
}

bool prime(int n) {
    if(n == 1) return false;
    else if(n == 2 || n == 3) return true;
    else if(n % 2 == 0) return false;
    else {
        for (int i = 3; i <= (int)ceil(sqrt(n)); i += 2)
            if(n % i == 0) return false;
        return true;
    }
}

void one(int* primes) {
    int sum = 
}

int* primeArray() {
    int *primes = calloc(10000, sizeof(int));
    int index = 0;
    int n = 2;
    do {
        if(prime(n)) {
            primes[index] = n;
            index++;
        }
        n++;
    } while(n * n < 50000000);
    return primes;
}

int main() {
    int *primes = primeArray();
    one(primes);
    combs(primes, 0, 0, 0);
    printf("%d\n", count);
    free(primes);
    return 0;
}
