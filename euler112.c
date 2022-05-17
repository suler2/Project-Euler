#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool bouncy(int n) {
    bool decreasing = false;
    bool increasing = false;
    while (n >= 10) {
        if((n % 10) > ((n / 10) % 10)) increasing = true;
        else if ((n % 10) < ((n / 10) % 10)) decreasing = true;
        n = n / 10;
    }
//    if(increasing && decreasing || !increasing && !decreasing) return true;
    if(increasing && decreasing) return true;
    else return false;
}

int main() {
    long num_bouncy = 0;
    long num_non_bouncy = 99;
    int current = 100;
    while(true) {
        if(bouncy(current)) num_bouncy++;
        else num_non_bouncy++;
        if(num_bouncy == 99 * num_non_bouncy) break;
        else current++;
    }
    printf("%d\n", current);
    return 0;
}
