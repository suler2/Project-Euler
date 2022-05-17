#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool abundant(int n) {
    int sum = 0;
    for (int i = 2; i < n; i++)
        if((n % i) == 0)
            sum = sum + i + n / i;
    return (n < (sum + 1)) ? true : false;
}

int main() {
    int sum = 0;
    bool* table = (bool*)calloc(28124, sizeof(bool));
    bool* table2 = (bool*)calloc(28124, sizeof(bool));
    for (int i = 12; i < 28124; i++) {
        if(!table[i] && abundant(i)) {
//            for(int j = i + i; j < 28124; j = j + i)
                table[i] = true;
        }
    }
    for (int i = 12; i < 28124; i++) {
        if(table[i]) {
            for (int j = i; j < 28124; j++) {
                if(table[j] && (i + j) < 28124) {
                    table2[i + j] = true;
                }
            }
        }
    }
    for (int i = 0; i < 28124; i++) {
        if(!table2[i]) sum = sum + i;
//        if(table[i] && i < 1000)printf("%d ", i);
    }
    printf("\n");
    printf("%d\n", sum);
    return 0;
}
