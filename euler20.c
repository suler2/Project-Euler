#include <stdio.h>

#define DIG 200

int digits[DIG];

void get100();

int main() {
    int sum = 0;
    digits[DIG - 1] = 1;
    get100();
    for (int i = 0; i < DIG; i++) {
        sum += digits[i];
        printf("%d", digits[i]);
    }
    printf("\n%d\n", sum);
    return 0;
}

void get100() {
    for (int i = 2; i <= 100; i++) {
        int carry = 0;
        for (int j = DIG - 1; j >= 0; j--) {
            int produkt = digits[j] * i;
            digits[j] = produkt % 10 + carry;
            carry = produkt / 10 + digits[j] / 10;
            digits[j] = digits[j] % 10;
        }
    }
}
