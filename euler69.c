#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int totient(int n);
bool *make_sieve(int n);

int main() {
    double max = 0;
    int max_nr = 0;
    for (int i = 2; i <= 100; i++) {
        printf("\nStevilo %d: ", i);
        double res = i / totient(i);
        printf("res = %f\n", res);
        if(res > max) {max = res; max_nr = i;}
    }
    printf("\nmax = %f, max_nr = %d\n", max, max_nr);
    return 0;
}

int totient(int n) {
    int count = 0;
    bool *sieve = make_sieve(n);
    for (int i = 0; i < n - 2; i++) {
        if(!sieve[i]) {
//            printf("%d ", i + 2);
            count++;
        }
    }
    free(sieve);
    return count + 1;
}

bool *make_sieve(int n) {
    bool *sieve = malloc((n - 2) * sizeof(bool));
    for (int i = 2; i < n; i++) {
        if((n % i) == 0) {
            int j = 1;
            while(i * j < n) {
                sieve[i * j - 2] = true;
                j++;
            }
        }
    }
    return sieve;
}
