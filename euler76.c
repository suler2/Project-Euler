#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int memo[101][101];

long vsote(int stevilo, int skupno) {
    int sum = 0;
    if(!stevilo && !skupno) {
        return 1;
    }
    else if (!stevilo && skupno) {
        return 0;
    }
    
    if(memo[stevilo - 1][skupno] == 0) {
        memo[stevilo - 1][skupno] = vsote(stevilo - 1, skupno);
    }
    sum += memo[stevilo - 1][skupno];
    
    if(skupno - stevilo < stevilo) {
        if(memo[skupno - stevilo][skupno - stevilo] == 0)
            memo[skupno - stevilo][skupno - stevilo] = vsote(skupno - stevilo, skupno - stevilo);
        sum += memo[skupno - stevilo][skupno - stevilo];
    }
    else {
        if(memo[stevilo][skupno - stevilo] == 0)
        memo[stevilo][skupno - stevilo] = vsote(stevilo, skupno - stevilo);
        sum += memo[stevilo][skupno - stevilo];
    }
    
    return sum;
}

int main() {
    int n = 100;
    printf("\nStevilo vsot: %ld\n", vsote(n - 1, n));
    return 0;
}
