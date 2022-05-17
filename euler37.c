#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool prime(long n);
bool trunctable(long n);
bool left(long n);
bool right(long n);

int main() {
    int count = 0;
    long sum = 0;
    long n = 12;
    while (count < 11) {
        if(trunctable(n - 1)) {
            printf("%ld\n", n - 1);
            count++;
            sum += n - 1;
        }
        if(trunctable(n + 1)) {
            printf("%ld\n", n + 1);
            count++;
            sum += n + 1;
        }
        n += 6;
    }
    printf("%ld\n", sum);
    return 0;
}

bool trunctable(long n) {
    if(prime(n) && right(n) && left(n)) return true;
    else return false;
}

bool right(long n) {
    int mod = 10;
    while(n > mod) {
        if(!prime(n % mod)) return false;
        mod = mod * 10;
    }
    return true;
}

bool left(long n) {
    while(n > 0) {
        if(!prime(n)) return false;
        n = n / 10;
    }
    return true;
}

bool prime(long n) {
    if (n == 2) return true;
    else if(n == 1 || (n % 2) == 0) return false;
    else {
        for (int i = 3; i <= (int)ceil(sqrt(n)); i += 2)
            if((n % i) == 0) return false;
        return true;
    }
}

