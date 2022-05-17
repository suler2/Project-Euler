#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool pandigital(long n);
bool div2(int n);
bool div3(int n);
bool div5(int n);
bool div7(int n);
bool div11(int n);
bool div13(int n);
bool div17(int n);

int main() {
    long sum = 0;
    for (long i = 1023456798; i <= 9876543210; i = i + 6) {
        if(pandigital(i)) {
            if(div17(i % 1000) && div13((i / 10) % 1000) && 
            div11((i / 100) % 1000) && div7((i / 1000) % 1000) && 
            div5((i / 10000) % 1000) && div3((i / 100000) % 1000) && 
            div2((i / 1000000) % 2) == 0) {
                sum += i;
            }
        }
    }
    printf("%ld\n", sum);
    return 0;
}

bool pandigital(long n) {
    bool *digits = (bool*)calloc(10, sizeof(bool));
    while (n > 0) {
        digits[n % 10] = !digits[n % 10];
        n = n / 10;
    }
    for (int i = 0; i < 10; i++)
        if(!digits[i]) return false;
    return true;
}

bool div2(int n) {
    if((n % 2) == 0) return true;
    else return false;
}
bool div3(int n) {
    if((n % 3) == 0) return true;
    else return false;
}
bool div5(int n) {
    if((n % 5) == 0) return true;
    else return false;
}
bool div7(int n) {
    if((n % 7) == 0) return true;
    else return false;
}
bool div11(int n) {
    if((n % 11) == 0) return true;
    else return false;
}
bool div13(int n) {
    if((n % 13) == 0) return true;
    else return false;
}
bool div17(int n) {
    if((n % 17) == 0) return true;
    else return false;
}
