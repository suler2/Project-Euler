#include <stdio.h>
#include <stdlib.h>

int coins[] = {200, 100, 50, 20, 10, 5, 2, 1};

int results(int coins[], int position, int remainder);

int main() {
    int sum = 0;
    sum += results(coins, 0, 200);
    printf("%d\n", sum);
    return 0;
}

int results(int coins[], int position, int remainder) {
    int sum = 0;
    if(remainder == 0 || position == 7) return 1;
    else if (remainder < 0 || position > 7) return 0;
    for (int i = position; i < 8; i++) {
        sum += results(coins, i, remainder - coins[i]);
    }
    return sum;
}
