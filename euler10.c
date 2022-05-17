#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define LIMIT 2000000

bool isPrime(int n);
long primes(int veckratnik);
int smallPrimes();

int main() {
    long sum = 0;
    sum = sum + smallPrimes() + primes((int)100000/6);
    printf ("%ld\n", sum);
    return 0;
}

bool isPrime(int n) {
    for (int i = 3; i <= (int) ceil(sqrt(n)); i = i + 1) {
        if ((n % i) == 0) {
            return false;
        }
    }
    return true;
}

int smallPrimes() {
    int sum = 0;
    int num[100000];
    for (int i = 0; i < 100000; i++)
        num[i] = i + 2;
    for (int i = 0; i < (int) ceil(sqrt(100000)); i++) {
        if (num[i] != 0) {
            for (int j = i + 1; j < 100000; j++) {
                if ((num[j] != 0) && (num[j] % num[i]) == 0)
                    num[j] = 0;
            }
        }
    }
    for (int i = 0; i < 100000; i++)
        sum = sum + num[i];
    return sum;
}

long primes(int i) {
    long sum = 0;
    while (i * 6 < LIMIT) {
        int n = 6 * i - 1;
        if (isPrime(n)) 
            sum = sum + n;
        int m = 6 * i + 1;
        if (isPrime(m))
            sum = sum + m;
        i++;
    }
    return sum;
}

/*
long primes(int veckratnik) {
    long sum = 0;
    int n = 6 * veckratnik - 1;
    if (isPrime(n)) sum = n;
    int m = 6 * veckratnik + 1;
    if (isPrime(m)) sum = sum + m;
    if (veckratnik * 6 > LIMIT) 
        return 0;
    else 
        return sum + primes(++veckratnik);
}
*/
