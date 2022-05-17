#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int pokrajsaj(int *stevec, int sizeStevec, int *imenovalec, int sizeImenovalec) {
    int stev = 1;
    int imen = 1;
    for (int i = sizeStevec - 1; i >= 0; i--) {
        for (int j = 0; j < sizeImenovalec; j++) {
            if(stevec[i] % imenovalec[j] == 0 && imenovalec[j] != 1) {
                stevec[i] = stevec[i] / imenovalec[j];
                imenovalec[j] = 1;
            }
        }
    }
    for (int i = 0; i < sizeStevec; i++) stev = stev * stevec[i];
    for (int i = 0; i < sizeImenovalec; i++) imen = imen * imenovalec[i];
    return stev / imen;
}

int formula(int n, int r) {
    if(n > 100) return 0;
    int max = 0;
    int index = 0;
    if(n - r >= r) {
        max = n - r;
        int *stevec = malloc((n - max) * sizeof(int));
        for (int i = max + 1; i <= n; i++) {stevec[index] = i; index++;}
        int *imenovalec = malloc(r * sizeof(int));
        for (int i = 1; i <= r; i++) imenovalec[i - 1] = i;
        int res = pokrajsaj(stevec, n- max, imenovalec, r);
        if(res > 1000000) return (n - r) - r + 1 + formula(n + 1, 1);
        else formula(n, r + 1);
    }
    else formula(n + 1, 1);
}

int main() {
    printf("%d\n", formula(2, 1));
    return 0;
}
