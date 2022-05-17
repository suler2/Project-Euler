#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool prime(int n) {
    if(n == 2) return true;
    else if(n % 2 == 0) return false;
    else {
        for (int i = 3; i <= (int) ceil(sqrt(n)); i += 2)
            if(n % i == 0) return false;
        return true;
    }
}

void dobiVeckratnike(int *nums, int veckratnik) {
    for (int i = veckratnik * veckratnik; i <= 100; i *= veckratnik) {
        nums[i] = veckratnik;
        printf("i = %d, vekcratnik = %d\n", i, veckratnik);
        if(veckratnik * veckratnik <= 100)
            dobiVeckratnike(nums, veckratnik * veckratnik);
    }
}

int dobiStevila(int *nums) {
    for (int i = 2; i <= 100; i++) {
        if(prime(i) && i * i <= 100) {
            dobiVeckratnike(nums, i);
        }
    }
    for (int i = 0; i <= 100; i++)
        printf("i = %d, nums[%d] = %d\n",i , i, nums[i]);
}

int main() {
    int count = 0;
    int *nums = calloc(101, sizeof(int));
    for (int i = 2; i <= 100; i++) nums[i] = 1;
    count += dobiStevila(nums);
    printf("\n%d\n", count);
    return 0;
}
