#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool check (long a) {
    int count = 0;
    for (long i = 2; i <= sqrt(a); i++) {
        if ((a % i) == 0) count++;
    }
    if (count > 0) return false;
    else return true;
}

long find (long a, int limit) {
    int max = 0;
    for (int i = 3; i <= limit; i++) {
        if ((a % i) == 0) {
            long b = a / i;
            if (check(i) && i > max)
                max = i;
            else if (check(b) && b > max)
                max = b;
        }
    }
    return max;
}

int main () {
    long a = 600851475143;
//    int limit = sqrt(600851475143);
    int limit = 775146;
    long res = find (a, limit);
    printf ("%ld\n", res);
    return 0;
}
