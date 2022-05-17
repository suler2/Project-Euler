#include <stdio.h>
#include <stdbool.h>

/*
palindrom 6D
100000x + 10000y + 1000z + 100z + 10y + 1x
100001x + 10010y + 1100z
11 * (9091x + 910y + 100z)
*/
int max = 0;

bool palindrom(int a) {
    int c = 0;
    for (int i = 0; i < 3; i++) {
        c = 10 * c + (a % 10);
        a = a / 10;
    }
    if (c == a) return true;
    else return false;
}

int find (int a, int b) {
    if (a <= 100 || b <= 100)
        return 0;
    else if ((a * b) < max)
        return find (a - 11, 999);
    else if (palindrom(a * b)) {
        if ((a * b) > max) max = a * b;
        return find (a, b - 1);
    }
    else if (b <= a)
        return find(a - 11, 999);
    else
        return find(a, b - 1);
}

int main () {
    int a = find (990, 999);
    printf ("%d\n", max);
    return 0;
}
