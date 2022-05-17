#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIM 10000000

int squares[10] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
int memo[LIM];

bool square89(long n, long n2);

int main() {
    int count = 0;
    for (long i = 1; i < LIM; i++) {
        if(square89(i, i)) count++;
    }
    printf("%d\n", count);
    return 0;
}

bool square89(long n, long n2) {
    if(n2 == 1) {
        if(n < LIM) memo[n] = -1;
        return false;
    }
    else if (n2 == 89) {
        if(n < LIM) memo[n] = 1;
        return true;
    }
    else {
        long sum = 0;
        while (n2 > 0) {
            sum += squares[n2 % 10];
            n2 = n2 / 10;
        }
        if(sum < LIM && memo[sum] == -1) return false;
        else if (sum < LIM && memo[sum] == 1) return true;
        else return square89(n, sum);
    }    
}
