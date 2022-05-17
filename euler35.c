#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define UPPER 1000000

int each_check(int n, bool* c_prime);
bool prime(int n);
int len_n(int n);
int perm(int n, int len);

int main() {
    bool *c_prime = (bool*)calloc(UPPER, sizeof(bool));
    c_prime[2] = true;
    c_prime[3] = true;
    int count = 2;
    for (int i = 6; i < UPPER; i = i + 6) {
        if(!c_prime[i - 1] && prime(i - 1))
            count += each_check(i - 1, c_prime);
        if(!c_prime[i + 1] && prime(i + 1))
            count += each_check(i + 1, c_prime);
    }
    printf("%d\n", count);

//    for (int i = 0; i < 1000; i++) if(c_prime[i]) printf("%d ", i);
//    printf("\n");

    return 0;
}

int each_check(int n, bool* c_prime) {
    int len = len_n(n);
    int *p = (int*)calloc(len, sizeof(int));
    p[0] = n;
    int count = 1;
    for(int i = 1; i < len; i++) {
        if(n != perm(n, len)) {
            n = perm(n, len);
            if(prime(n)) {
                p[i] = n;
                count++;
            }
        }
        else {
            free(p);
            return 1;
        }
    }
    if(count == len) {
        for (int i = 0; i < len; i++) {
            c_prime[p[i]] = true;
            printf("%d ", p[i]);
        }
        printf("\n");
        
        free(p);
        return count;
    }
    else {    
        free(p);
        return 0;
    }
}

bool prime(int n) {
    int count = 0;
    for (int i = 2; i <= (int)ceil(sqrt(n)); i++)
        if((n % i) == 0) count++;
    if(count == 0) return true;
    else return false;
}

int len_n(int n) {
    int count = 0;
    while(n > 0) {
        count++;
        n = n / 10;
    }
    return count;
}

int perm(int n, int len) {
    int last = n % 10;
    n = n / 10;
    for (int i = 1; i < len; i++)
        last = last * 10;
    return last + n;
}
