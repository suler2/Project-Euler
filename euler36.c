#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIL 20

int pow2[MIL];

bool palindrom10(int n);
bool palindrom2(int *n, int size);
int size(int lim);
int power(int base, int p);
int *to_base_2(int n, int size);

int main() {
    for (int i = 0; i < MIL; i++)
        pow2[i] = power(2, i);
    int sum = 0;
    for (int i = 1; i < 1000000; i++) {
        if(palindrom10(i) && !((i % 2) == 0)) {
            int size_base_2 = size(i);
//            printf("size = %d, i = %d\n", size_base_2, i);
            int *base_2 = to_base_2(i, size_base_2);
            if(palindrom2(base_2, size_base_2)) {
                printf("%d ", i);
                sum += i;
            }
            /*
            for (int i = 0; i < size_base_2; i++) {
                printf("%d", base_2[i]);
            }
            printf("\n");
            */
        }
    }
    printf("\n%d\n", sum);
    return 0;
}

int power(int base, int p) {
    if(p == 0) return 1;
    else if (p == 1) return base;
    else return base * power(base, p - 1);
}

bool palindrom10(int x) {
    int y = x;
    int z = 0;
    while(y > 0) {
        z = 10 * z + (y % 10);
        y = y / 10;
    }
    if(x == z) return true;
    else return false;
}

bool palindrom2(int *n, int size) {
    for (int i = 0; i < size / 2; i++) {
        if(n[i] != n[size - i - 1]) return false;
    }
    return true;
}

int size(int lim) {
    int n = 2;
    int count = 1;
    while (n < lim + 1) {
        n = n * 2;
        count++;
    }
    return count;
}

int *to_base_2(int n, int size) {
    int *base = (int*)calloc(size, sizeof(int));
    int j = 0;
    for (int i = size - 1; i >= 0; i--) {
        if(pow2[i] <= n) {
            base[j] = 1;
            n = n - pow2[i];
        }
        if (n == 0) break;
        j++;
    }
    return base;
}
