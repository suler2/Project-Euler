#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 10000000

int** readLines();
int number(char* line, int start, int end);
int length(int base, int exp);
int* power(int* number, int base, int exp);

int main() {
    int maxLen = 0;
    int** nums = readLines();
    for (int i = 0; i < 1000; i++) {
        int len = length(nums[i][0], nums[i][1]);
        if(len > maxLen) len = maxLen;
    }
    printf("%d\n", maxLen);
    free(nums);
    return 0;
}

int** readLines() {
    char* line = calloc(100, sizeof(char));
    int** nums = malloc(1000 * sizeof(int*));
    for (int i = 0; i < 1000; i++)
        nums[i] = calloc(2, sizeof(int));
    FILE *f = fopen("euler99.txt", "r");
    for (int i = 0; i < 1000; i++) {
        fgets(line, 100, f);
        int j = 0;
        while(line[j] != ',') j++;
        nums[i][0] = number(line, 0, j);
        nums[i][1] = number(line, j + 1, strlen(line));
    }
    fclose(f);
    return nums;
}

int number(char* line, int start, int end) {
    int n = 0;
    for (int i = start; i < end; i++) {
        n = n * 10 + (line[i] - '0');
    }
    return n;
}

int length(int base, int exp) {
//    printf("%d, %d\n", base, exp);
    int len = 0;
    int* number = calloc(SIZE * sizeof(int));
    len = power(number, base, exp);
    return len;
}

int power(int* number, int base, int exp) {
}
