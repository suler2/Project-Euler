#include <stdio.h>

int primes[100];

/*
2 * 2 * 2 * 2
3 * 3
5
7
11
13
17
19
*/
int prime(int a) {
    int count = 2;
    for (int i = 2; i < a; i++)
        if ((a % i) == 0) count++;
    return count;
}

int notprime(int a, int c, int lim) {
    if (c >= lim || a <= 1) 
        return a;
    else if ((a % primes[c]) == 0 && (a / primes[c]) > 1) {
        return notprime(a / primes[c], c, lim);
    }
    else 
        return notprime(a, c + 1, lim);
}

int main() {
    long n = 1;
    int countpr = 0;
    for (int i = 2; i <= 20; i++) {
        if (prime(i) == 2) {
            primes[countpr] = i;
            n = n * i;
            countpr++;
        }
        else {
            n = n * notprime(i, 0, countpr);
        }
     }
     printf ("%ld\n", n);
    return 0;
}
