#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int bouncy(int* googol);
int get_non_bouncy(int *googol, int leadingZero, int index, int number);
void carry(int *googol, int index);

int main() {
    int* googol = calloc(101, sizeof(int));
    googol[98] = 1;
    long count = 100;
    count += get_non_bouncy(googol, 98, 100, 1);
    printf("%ld\n", count);
    free(googol);
    return 0;
}

void carry(int *googol, int index) {
    googol[index]++;
    if(googol[index] == 10) {
        googol[index] = 0;
        carry(googol, index - 1);
    }
}

int get_non_bouncy(int *googol, int leadingZero, int index, int number) {
    if(googol[97] == 1) return 0;
    else {
        if(bouncy(googol) == 1 && googol[100] < 10) {
            return (10 - googol[100]) + get_non_bouncy(googol, leadingZero, index, 10);
        }
        else if(bouncy(googol) == -1 && googol[100] < 10) {
            return googol[100] + get_non_bouncy(googol, leadingZero, index, googol[100]);
        }
        else {
            if(number == 10) {
                number = 0;
                carry(googol, index - 1);
            }
            googol[index] = number;
            get_non_bouncy(googol, leadingZero, index, number + 1);
        }
    }
}

int bouncy(int* googol) {
    bool decreasing = false;
    bool increasing = true;
    int index = 0;
    while (googol[index] == 0) index++;
    while (index < 100) {
        if(googol[index] > googol[index + 1]) decreasing = true;
        else if (googol[index] < googol[index + 1]) increasing = true;
        index++;
    }
    if(increasing && !decreasing || !increasing && !decreasing) return 1;
    else if(decreasing && !increasing) return -1;
    else return 0; 
}

