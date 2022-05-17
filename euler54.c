#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

struct Player {
    bool handColor;
    int play;
    int *orderedNumbers;
    struct {
        char color;
        int number;
    } cards[5];
};

enum Hand {
    HighCard,
    Pair,
    TwoPairs,
    ThreeKind,
    Straight,
    Flush,
    FullHouse,
    FourKind,
    StraightFlush
};

int getNumber(char n);
bool getHandColor(struct Player player);
int playLine(struct Player player1, struct Player player2);
void sortSize(struct Player player);
int getPlay(struct Player player);
int checkNumbers(int *numbers);
int *switchNumbers(int *numbers, int start, int lim, int size);

int main() {
    int result = 0;

    FILE *file = fopen("euler54.txt", "r");
    char *card = calloc(3, sizeof(char));
    struct Player player1;
    player1.orderedNumbers = calloc(5, sizeof(int));
    struct Player player2;
    player2.orderedNumbers = calloc(5, sizeof(int));
    
    int index = 0;
    while(fscanf(file, "%s", card) != EOF) {
        if(index == 10) {
            index = 0;
            result += playLine(player1, player2);
            player1.cards[index].color = card[1];
            player1.cards[index].number = getNumber(card[0]);

        }
        else if(index < 5) {
            player1.cards[index].color = card[1];
            player1.cards[index].number = getNumber(card[0]);
        }
        else if (index >= 5 && index < 10) {
            player2.cards[index - 5].color = card[1];
            player2.cards[index - 5].number = getNumber(card[0]);
        }
        index++;
    }
    result += playLine(player1, player2);
    
    printf("%d\n", result);

    return 0;
}

int getNumber(char n) {
    if(n >= '2' && n <= '9') return n - '0';
    else if (n == 'T') return 10;
    else if (n == 'J') return 11;
    else if (n == 'Q') return 12;
    else if (n == 'K') return 13;
    else if (n == 'A') return 14;
    else return -1;
}


void sortSize(struct Player player) {
    int *copy = calloc(5, sizeof(int));
    int max = INT_MIN;
    int index = -1;
    for (int i = 0; i < 5; i++)
        copy[i] = player.cards[i].number;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if(copy[j] > max) {
                max = copy[j];
                index = j;
            }
        }
        copy[index] = INT_MIN;
        player.orderedNumbers[i] = max;
        max = 0;
    }
    free(copy);
}

bool getHandColor(struct Player player) {
    int color = player.cards[0].color;
    for (int i = 1; i < 5; i++) {
        int current = player.cards[i].color;
        if(color != current) return false;
    }
    return true;
}

int playLine(struct Player player1, struct Player player2) {
    sortSize(player1);
    sortSize(player2);
    player1.handColor = getHandColor(player1);
    player2.handColor = getHandColor(player2);
    player1.play = getPlay(player1);
    player2.play = getPlay(player2);
    
    if(player1.play > player2.play)
        return 1;
    else if (player1.play < player2.play)
        return 0;
    else {
        for (int i = 0; i < 5; i++) {
            if(player1.orderedNumbers[i] < player2.orderedNumbers[i]) return 0;
            else if(player1.orderedNumbers[i] > player2.orderedNumbers[i]) return 1;
        }
        return 0;
    }
}

int getPlay(struct Player player) {
    int play = checkNumbers(player.orderedNumbers);
    if(player.handColor && player.play != FourKind && player.play != Straight)
        player.play = Flush;
    else if (player.handColor && player.play == Straight)
        player.play = StraightFlush;
    return play;
}

int checkNumbers(int *numbers) {
    int consecutive = 0;
    int *copy = calloc(6, sizeof(int));
    for (int i = 0; i < 5; i++) copy[i] = numbers[i];
    int match = copy[0];
    for (int i = 1; i < 5; i++) {
        if (copy[i] == match - i) consecutive++;
        else break;
    }
    if (consecutive == 4) return Straight;
    
    bool two = false;
    bool twotwo = false;
    bool three = false;
    bool four = false;
    int same = 1;
    for (int i = 1; i < 6; i++) {
        if(copy[i] != match) {
            if (same == 4) {
                numbers = switchNumbers(numbers, 0, i, same);
                four = true;
            }
            else if (same == 3) {
                if (two) numbers = switchNumbers(numbers, 2, i, same);
                else numbers = switchNumbers(numbers, 0, i, same);
                three = true;
            }
            else if (same == 2 && two) {
                numbers = switchNumbers(numbers, 2, i, same);
                twotwo = true;
            }
            else if (same == 2 && !two) {
                if (three) numbers = switchNumbers(numbers, 3, i, same);
                else numbers = switchNumbers(numbers, 0, i, same);
                two = true;
            }
            match = copy[i];
            same = 1;
        }
        else {
            same++;
        }
    }
    if(twotwo) return TwoPairs;
    else if(four) return FourKind;
    else if (three && two) return FullHouse;
    else if (three) return ThreeKind;
    else if (two) return Pair;
    else return HighCard;
}

int *switchNumbers(int *numbers, int start, int lim, int size) {
    if ((lim - size) == start) return numbers;
    else {
        int number = numbers[lim - 1];
        int *aux = calloc(5, sizeof(int));
        for (int i = 0; i < 5; i++) aux[i] = numbers[i];
        for (int i = 0; i < size; i++) {
            for (int j = lim - 2; j >= start; j--) {
                numbers[j + 1] = numbers[j];
            }
            numbers[start + i] = number;
        }
    }
    return numbers;
}
