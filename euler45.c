#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long tri(long n);
long penta(long n);
long hex(long n);

int main() {
    long st = 286;
    long sp = 166;
    long sh = 144;
    long i = 0;
    while(true) {
//        long rt = tri(st);
        long rp = penta(sp);
        long rh = hex(sh);
        printf("%ld %ld ", rp, rh);
//        if(rt < rp && rt < rh) {st++; printf("1");}
        if(rp < rh) {sp++; printf("2");}
        else if(rh < rp) {sh++; printf("3");}
        else {
            printf("%ld\n", rp);
            break;
        }
        printf("\n");
        i++;
    }
    return 0;
}

long tri(long n) {
    return (n * (n + 1)) / 2;
}
long penta(long n) {
    return (n * (3 * n - 1)) / 2;
}

long hex(long n) {
    return n * (2 * n - 1);
}

