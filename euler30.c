#include <stdio.h>
#include <stdbool.h>

#define UPPER 355000

int power(int base, int p);
bool fifth(int n);

int main() {
    long sum = 0;
    for (int i = 2; i < UPPER; i++) {
        if(fifth(i)) sum += i;
    }
    printf("%ld\n", sum);
    return 0;
}

int power(int base, int p) {
    if(p == 1) return base;
    else return base * power(base, p - 1); 
}

bool fifth(int n) {
    int sum = 0;
    int num = n;
    while(num > 0) {
        sum += power(num % 10, 5);
        num = num / 10;
    }
    if(sum == n) return true;
    else return false;
}
