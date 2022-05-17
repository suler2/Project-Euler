#include <stdio.h>
#include <stdbool.h>

#define UPPER 2540161

int factorial(int n);
bool digits(int n, int cache[10]);

int main() {
    long sum = 0;
    static int cache[10];
    for (int i = 0; i < 10; i++)
        cache[i] = factorial(i);
    for (int i = 3; i < UPPER; i++) {
        if(digits(i, cache)) sum += i;
    }
    printf("%ld\n", sum);
    return 0;
}

int factorial(int n) {
    if (n == 0) return 1;
    else return n * factorial(n - 1);
}

bool digits(int n, int cache[10]) {
    int sum = 0;
    int num = n;
    while(num > 0) {
        sum += cache[num % 10];
        num = num / 10;
    }
    if(sum == n) return true;
    else return false;
}
