#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int trikotniki(int obseg) {
    int count = 0;
    for (int c = 5; c < ceil(obseg/2); c++) {
        for (int b = 1; b < c; b++) {
            int a = obseg - c - b;
            if(a < b) break;
//            printf("obseg = %d, c = %d, b = %d, a = %d\n", obseg, c, b, a);
            if((c * c) == (a * a + b * b)) {
//                printf("obseg = %d, c = %d, b = %d, a = %d\n", obseg, c, b, a);
                count++;
            }
        }
    }
    return count;
}

int main() {
    int lim = 1000;
    int max = 0;
    int maxObseg = 0;
    for (int obseg = 12; obseg <= lim; obseg++) {
        int current = trikotniki(obseg);
        if(current > max) {
            max = current;
            maxObseg = obseg;
        }
    }
    printf("%d\n", maxObseg);
    return 0;
}
