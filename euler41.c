#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

bool prime(long n);
bool pandigital(long n);

int main() {
    long max = 0;
    for (long i = 6; i <= 7654321; i += 6) {
        if(prime(i - 1) && pandigital(i - 1) && (i - 1) > max)
            max = i - 1;
        if(prime(i + 1) && pandigital(i + 1) && (i + 1) > max)
            max = i + 1;
    }
    printf("%ld\n", max);
    return 0;
}

bool prime(long n) {
    if(n == 2 || n == 3) return true;
    else if((n % 2) == 0) return false;
    else {
        for (long i = 3; i < (long)ceil(sqrt(n)); i += 2) {
            if((n % i) == 0) return false;
        }
        return true;
    }
}

bool pandigital(long n) {
    int *digits = (int*)calloc(10, sizeof(int));
    int max = 0;
    int count = 0;
    while(n > 0) {
        digits[n % 10]++;
        count++;
        n = n / 10;
    }
    if(digits[0] > 0) {
        free(digits);
        return false;
    }
    else if(!(count == 4 || count == 7)) {
        free(digits);
        return false;
    }
    else {
        count = 0;
        for(int i = 0; i < 10; i++) {
            if(digits[i] > 1) {
                free(digits);
                return false;
            }
            else if(digits[i] == 1) {
                max = i;
                count++;
            }
        }
    }
    if(count != max) {
        free(digits);
        return false;
    }
    else {
        free(digits);
        return true;
    }
}
