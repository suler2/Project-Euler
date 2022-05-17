#include <stdio.h>
#include <math.h>

int sumDivisors(int n);

int main() {
    int sum = 0;
    for (int i = 3; i < 10000; i++) {
        int j = sumDivisors(i);
        if(i == sumDivisors(j) && i != j) 
            sum = sum + i + j;
    }
    printf("%d\n", sum / 2);
    return 0;
}

int sumDivisors(int n) {
    int sum = 0;
    for (int i = 2; i <= (int)ceil(sqrt(n)); i++)
        if((n % i) == 0)
            sum = sum + n / i + i;
    return sum + 1;
}
