#include <stdio.h>
#include <stdlib.h>

unsigned long power(int base, int n);
int size(unsigned long n);
int nine();
int timesNine(int *digits, int inc);

int main () {
    int count = 1;
    for (int i = 2; i < 9; i++) {
        for (int j = 1; j < 20; j++) {
            if(size(power(i, j)) == j) {
//                printf("%d^%d = %lu\n", i, j, power(i, j));
                count++;
            }
            else break;
        }
    }
    count += nine();
    printf("%d\n", count);
    return 0;
}

int nine() {
    unsigned long largest = power(9, 20);
    printf("%lu\n", largest);
    int *digits = calloc(30, sizeof(int));
    for (int i = 29; i >= 10; i--) {
        digits[i] = largest % 10;
        largest = largest / 10;
    }
    for (int i = 0; i < 30; i++) {
        printf("%d", digits[i]);
    }
    printf("\n");
    int count = timesNine(digits, 20);
//    printf("%d");
    free(digits);
    return count;
}

int timesNine(int *digits, int inc) {
    int n = 0;
    for (int i = 0; i < 30; i++) {
        if(digits[i] != 0) break;
        n++;
    }
//    printf("%d\n", n);
    if(30 - n < inc) return 30 - n;
    else {
        int carry = 0;
        for (int i = 29; i >= 0; i--) {
//            printf("%d\n", carry);
            int produkt = digits[i] * 9;
            digits[i] = produkt % 10 + carry;
            carry = produkt / 10 + digits[i] / 10;
            digits[i] = digits[i] % 10;
//            printf("%d ", carry);
        }
        for (int i = 0; i < 30; i++) {
            printf("%d", digits[i]);
        }
        printf("\n");
        return timesNine(digits, inc + 1);
    } 
}

int size(unsigned long n) {
    int count = 0;
    while(n > 0) {
        count++;
        n = n / 10;
    }
    return count++;
}

unsigned long power(int base, int n) {
    if (n == 1) return base;
    else return base * power(base, n - 1);
}
