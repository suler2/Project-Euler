#include <stdio.h>
#include <stdbool.h>

int digits[1000];
void getDigits(int lim);

int main() {
    int sum = 0;
    digits[999] = 2;
    getDigits(1000);
    for (int i = 0; i < 1000; i++) {
//        if(digits[i] != 0)printf("%d", digits[i]);
        sum += digits[i];
    }
    printf("\n");
    printf("%d\n", sum);
    return 0;
}

void getDigits(int lim) {
    bool carry = false;
//    printf("HERE\n");
    if (lim == 1) {}
    else {
        for (int i = 999; i >= 0; i--) {
            digits[i] = digits[i] * 2;
            if(carry) {
                digits[i]++;
                carry = false;
            }
            if(digits[i] >= 10) {
                digits[i] = digits[i] % 10;
                carry = true;
            }
        }
        getDigits(lim - 1);
    }
}
