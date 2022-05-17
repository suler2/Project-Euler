#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int prime(int n) {
    for (int i = 3; i < (int) ceil(sqrt(n)); i += 2)
        if(n % i == 0) return false;
    return true;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    int sum = n;
    
    int divisor = 2;
    int cube = 0;
    while(n > 0) {
        if(n % divisor == 0) {
            cube++;
        }
        else {
            if(cube >= 3) {
                for (int i = 1; i <= cube - 2; i++) {
                    sum += i;
                }
            }
            if (n == 1) n--;
            divisor++;
            cube = 0;
        }
        n = n / divisor;
    }
   
    printf("%d\n", sum);
    return 0;
}
