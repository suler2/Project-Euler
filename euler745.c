#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIM 100000000000000

bool prime(int n) {
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    for (int i = 3; i <= (int) ceil(sqrt(n)); i += 2) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    int count = 0;
    for(int i = 1; i <= (int) ceil(sqrt(LIM)); i++) {
        
    }
    return 0;
}
