#include <stdio.h>
#include <string.h>

int grid[20][20];

void readGrid();
void readLine();
void printGrid();
int findMaxLine();
int findMaxDiag();

int main() {
    int maxL = 0;
    int maxD = 0;
    readGrid();
//    printGrid();
    maxL = findMaxLine();
    maxD = findMaxDiag();
    if(maxL > maxD) printf("%d\n", maxL);
    else printf("%d\n", maxD);
    return 0;
}

void readLine(int i) {
    char c;
    int j = 0;
    int k = 0;
    while (c = getchar()) {
        if (c == ' ') {
            grid[i][j] = k;
            k = 0;
            j++;
        }
        else if (c == '\n' || c == EOF) {
            grid[i][j] = k;
            break;
        }
        else k = 10 * k + c - '0';
    }
}

void readGrid() {
    for (int i = 0; i < 20; i++) {
        readLine(i);
    }
}

int findMaxLine() {
    int max = 0;
    int sumH = 0;
    int sumV = 0;
    for (int i = 0; i < 20; i++) {
        sumH = grid[i][0] + grid[i][1] + grid[i][2] + grid[i][3];
        sumV = grid[0][i] + grid[1][i] + grid[2][i] + grid[3][i];
        if (sumH > max) max = sumH;
        if (sumV > max) max = sumV;
        for (int j = 4; j < 20; j++) {
            sumH = sumH + grid[i][j] - grid[i][j - 4];
            sumV = sumV + grid[j][i] - grid[j - 4][i];
            if (sumH > max) {
                max = sumH;
                printf("%d %d %d %d\n", grid[i][j-3], grid[i][j-2], grid[i][j-1], grid[i][j]);
            }
            if (sumV > max) {
                max = sumV;
                printf("%d %d %d %d\n", grid[j-3][i], grid[j-2][i], grid[j-1][i], grid[j][i]);
            }
        }
    }
    return max;
}

int findMaxDiag() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            
        }
    }
    return max;
}

void printGrid() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            printf("%d ", grid[i][j]);
        }
    printf("\n");
    }
}
