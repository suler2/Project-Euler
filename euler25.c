#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void sestej(int *n0, int *n1, int *n2, int index, int carry) {
    n0[index] = (n1[index] + n2[index] + carry) % 10;
    int novi = (n1[index] + n2[index] + carry) / 10;
    if(index == 0) return;
    else sestej(n0, n1, n2, index - 1, novi);
}

int dobiIndex(int **number, int index) {
    if(number[0][0] != 0 || number[1][0] != 0 ||
       number[2][0] != 0) return 0;
    else {
        sestej(number[index % 3], number[(index + 1) % 3], 
               number[(index + 2) % 3], 999, 0);
        return 1 + dobiIndex(number, index + 1);
    }
}

long small(int index, long *fib) {
    return fib[index - 1] + fib[index - 2];
}

int *convert(long number) {
    int *ptr = calloc(1000, sizeof(int));
    int index = 999;
    while (number > 1) {
        ptr[index--] = number % 10;
        number = number / 10;
    }
    return ptr;
}

int main() {
    long *fib = calloc(100, sizeof(long));
    fib[1] = 1; fib[2] = 1;
    int index = 2;
    while(fib[index++] >= 0) { 
        fib[index] = small(index, fib);
    }
    
    index -= 2;
    int **number = malloc(3 * sizeof(int*));
    number[0] = calloc(1000, sizeof(int));
    number[1] = convert(fib[index - 1]);
    number[2] = convert(fib[index]);
    
    index += dobiIndex(number, 0);
    printf("%d\n", index);
    for (int i = 0; i < 3; i++) free(number[i]);
    free(number);
    return 0;
}
