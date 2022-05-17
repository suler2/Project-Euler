#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool jePitagorejsko (int c) {
    for (int a = 499; a > c; a--) {
        int b = 1000 - a - c;
        if (b * b == a * a - c * c) {
            printf ("a = %d, b = %d, c = %d\n", a, b, c);
            printf ("%d\n", a * b * c);
            return true;
        }
    } 
    return false;
}

int main() {
    for (int c = 499; c > 0; c--) {
        if (jePitagorejsko(c)) {
            
            break;
        }
    }
    return 0;
}
