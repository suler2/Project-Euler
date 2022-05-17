#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPrime (int n) {
    for (int i = 3; i <= (int) ceil(sqrt(n)); i++)
        if ((n % i) == 0)
            return false;
    return true;
}

long recursive (int veckratnik, int stPrastevil) {
    int n = 6 * veckratnik - 1;
    int m = 6 * veckratnik + 1;
    int prime = 0;
    if (isPrime(n)) {
        prime = n;
        stPrastevil++;
    }   
    if (stPrastevil >= 10001) {
        return prime;
    }
    if (isPrime(m)) {
        prime = m;
        stPrastevil++;
    }
    if (stPrastevil >= 10001) {
        return prime;
    }
    else return recursive(++veckratnik, stPrastevil);
}

int main() {
    long result = recursive(1, 2);
    printf ("%ld\n", result);
    return 0;
}
