#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool prime(long n);

int main() {
    long number = 1;
    int primes = 0;
    int counter = 0;
    int size = 2;
    int turn = 0;
    int total = 0;
    while (1) {
        if (turn < 4 && counter == size) {
            turn++;
            counter = 0;
            total++;
            if(prime(number)) {
                primes++;
//                printf("%ld ", number);
            }
            if(((double)primes / (double)total) < 0.10) break;
            if(turn == 4) {
                turn = 0;
                size += 2;
            }
        }
        counter++;
        number++;
    }
    printf("%d\n", size - 1);
    return 0;
}

bool prime(long n) {
    if((n % 2) == 0) return false;
    for (int i = 3; i <= (int)ceil(sqrt(n)); i = i + 2) {
        if((n % i) == 0) return false;
    }
    return true;
}
