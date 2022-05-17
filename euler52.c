#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool permutation(int *digits1, int m, int len);
int *fill(int n, int len);
int size(int n);
int power(int base, int n);

int main() {
    int n = 100;
    int len = size(n);
    while (true) {
        int count = 1;
        int *digits = fill(n, len);
        for (int i = 2; i <= 6; i++) {
            if (!permutation(digits, n * i, len)) break;
            else count++;
        }
        if(count == 6) break;
        if(len < size(n * 6)) {
            len++;
            n = power(10, len);
        }
        else n++;
    }
    printf("%d\n", n);
    return 0;
}

bool permutation(int *digits1, int m, int len) {
    int *digits2 = fill(m, len);
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if(digits1[i] == digits2[j]) {
                count++;
                digits2[j] = -1;
                break;
            }
        }
    }
    if(count == len) return true;
    else return false;
}

int *fill(int n, int len) {
    int *digits = malloc(len * sizeof(int));
    int i = 0;
    while(n > 0) {
        digits[i] = n % 10;
        n = n / 10;
        i++;    
    }
    return digits;
}

int size(int n) {
    int count = 0;
    while (n > 0) {
        count++;
        n = n / 10;
    }
    return count;
}

int power(int base, int n) {
    if(n == 0) return 1;
    else if (n == 1) return 1;
    else base * power(base, n - 1);
}
