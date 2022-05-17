#include <stdio.h>
#include <math.h>

int div(int n, int a);

int main() {
    int n = 1;
    int i = 2;
    int res = 0;
    while (res < 500) {
        n = n + i;
        res = div(n, 2);
        i++;
    }
    printf("%d\n", n);
    return 0;
}

int div(int n, int a) {
    int count = 2;
    for (int i = 2; i < (int) ceil(sqrt(n)); i++) {
        if ((n % i) == 0) count = count + 2;
    }
    return count;
}
