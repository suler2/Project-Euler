#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIM 2357207

int digits[LIM];
int timesTwo = 7830457;
void init() {
    digits[LIM - 1] = 3; digits[LIM - 2] = 3;
    digits[LIM - 3] = 4; digits[LIM - 4] = 8;
    digits[LIM - 5] = 2;
}
void times_two_plus_one() {
    int lim = 5;
    bool carry = false;
    for (int i = 0; i < timesTwo; i++) {
        for (int j = LIM - 1; j >= LIM - lim; j--) {
            digits[j] = digits[j] * 2;
            if(carry) {
                digits[j]++;
                carry = false;
            }
            if(digits[j] >= 10) {
                carry = true;
                digits[j] = digits[j] % 10;
            }
        }
        if(carry) {
            lim++;
            digits[LIM - lim] = 1;
        }
    }
    digits[LIM - 1]++;
}

int main() {
    init();
    times_two_plus_one();
    for (int i = LIM - 10; i < LIM; i++) {
        printf("%d", digits[i]);
    }
    printf("\n");
    return 0;
}
