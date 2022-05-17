#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *loop(int min1, int max1, int min2, int max2, int index, int *sum);
bool pandigital(int x, int y, int z);
bool *get_digits(int n, bool *digits);
int get_count(int n);
int get_sum(int in, int *p);

int main() {
    int index = 0;
    int *products = (int*)calloc(100, sizeof(int));
    products = loop(1, 9, 1000, 9999, index, products);
    for (int i = 0; i < 100; i++) if(products[i] != 0) index++;
    products = loop(10, 99, 100, 999, index + 1, products);
    int sum = get_sum(index, products);
    printf("%d\n", sum);
    return 0;
}

int *loop(int min1, int max1, int min2, int max2, int index, int *sum) {
    int k = index;
    for(int i = min1; i <= max1; i++) {
        for (int j = min2; j <= max2; j++) {
            if(pandigital(i, j, i * j)) {
                sum[k] = i * j;
                k++;
            }
        }
    }
    return sum;
}

bool pandigital(int x, int y, int z) {
    int count = 0;
    bool *digits = (bool*)calloc(10, sizeof(bool));
    digits = get_digits(x, digits);
    digits = get_digits(y, digits);
    digits = get_digits(z, digits);
    count += get_count(x);
    count += get_count(y);
    count += get_count(z);
    if(count == 9) {
        if(!digits[0]) {
            for (int i = 1; i < 10; i++)
                if(!digits[i]) return false;
        }
        else return false;
    }
    else return false;
    printf("%d * %d = %d\n", x, y, z);
    return true;
}

bool *get_digits(int n, bool *digits) {
    while(n > 0) {
        digits[n % 10] = !digits[n % 10];
        n = n / 10;
    }
    return digits;
}

int get_count(int n) {
    int count = 0;
    while(n > 0) {
        n = n / 10;
        count++;
    }
    return count;
}

int get_sum(int in, int *p) {
    int sum = 0;
    for (int i = 0; i < 100 || p[i] == 0; i++) {
        bool same = false;
        for (int j = i; j < 100 || p[j] == 0; j++) {
            if (p[i] == p[j]) {
                same = !same;
            }
        }
        if(same) sum += p[i];
    }
    return sum;
}
