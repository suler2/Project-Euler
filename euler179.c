#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define LIM 700

int sqrtLim = (int) ceil(sqrt(LIM));
int nums[LIM];

int high_divisors(int *divisors) {
    int prev = divisors[sqrtLim - 1];
    for (int i = sqrtLim; i < LIM; i++) {
        int divs = 2;
        int lim = i;
        for (int j = 2; j < lim; j++) {
            if(i % j == 0) {
                divs++;
                lim = lim / j;
            }
        }
    } 
}

int low_divisors(int *divisors) {
    int count = 0;
    for (int i = 1; i < sqrtLim; i++) {
        if(divisors[i - 1] == divisors[i]) count += 2;
    }
    return count;
}

int get_divisors(int n) {
    int count = 1;
    for (int i = 2; i <= n; i++) {
        if(n % i == 0) count++;
    }
    return count;
}

int main() {
    int count = 0; 
    int *divisors = calloc(sqrtLim, sizeof(int));
    divisors[1] = 1;
    divisors[2] = 2;
    for(int i = 3; i < sqrtLim; i++) {
        divisors[i] = get_divisors(i);
    }
    count += low_divisors(divisors);
    count += high_divisors(divisors);
    for (int i = 0; i < sqrtLim; i++) {
        printf("nr: %d, divs: %d\n", i, divisors[i]);
    }
    printf("%d\n", count);
    free(divisors);
    return 0;
}
