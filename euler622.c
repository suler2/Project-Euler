#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CARDS 52

int main() {
    int *star = calloc(CARDS, sizeof(int));
    int *deck = calloc(CARDS, sizeof(int));
    for (int i = 0; i < CARDS; i++) {
        star[i] = i;
        deck[i] = i;
    }
    
    int *new = calloc(CARDS, sizeof(int));
    for (int i = 0; i < 8; i++) {
        int *tmp = calloc(CARDS, sizeof(int));
        for (int j = 0; j < CARDS; j++) {
            tmp[j] = deck[j];
        }
        for (int j = 0; j < CARDS / 2; j++) {
            deck[j * 2] = tmp[j];
            deck[j * 2 + 1] = tmp[j + 26];
        }
        for (int j = 0; j < CARDS - 1; j++) {
            printf("%d, ", deck[j]);
        }
        free(tmp);
        printf("%d\n", deck[CARDS - 1]);
    }
    
    free(star);
    free(deck);
    return 0;
}
