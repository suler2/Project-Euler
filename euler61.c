#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM 300
#define UPPER 10000
#define LOWER 1000

int triangleSet[NUM];
int squareSet[NUM];
int pentagonalSet[NUM];
int hexagonalSet[NUM];
int heptagonalSet[NUM];
int octagonalSet[NUM];

int triangle(int n);
int square(int n);
int pentagonal(int n);
int hexagonal(int n);
int heptagonal(int n);
int octagonal(int n);

void fillSets();
void findSet();
bool checkCyclic(int first, int last);
void checkLoops(int **set1, int **set2, int **set3, int lim1, int lim2, int lim3);

int main() {
    fillSets();
    findSet();
    return 0;
}

void findSet() {
    int **set1 = calloc(1000, sizeof(int*));
    int **set2 = calloc(1000, sizeof(int*));
    int **set3 = calloc(1000, sizeof(int*));
    for (int i = 0; i < 1000; i++) {
        set1[i] = calloc(2, sizeof(int));
        set2[i] = calloc(2, sizeof(int));
        set3[i] = calloc(2, sizeof(int));
    }
    int x = 0;
    int y = 0; 
    int z = 0;
    for (int i = 0; i < NUM; i++) {
        for (int j = 0; j < NUM; j++) {
            if(checkCyclic(triangleSet[i], squareSet[j]) && 
                    triangleSet[i] != 0 && squareSet[j] != 0) {
                set1[x][0] = triangleSet[i];
                set1[x][1] = squareSet[j];
                x++;
            }
            if(checkCyclic(pentagonalSet[i], hexagonalSet[j]) && 
                    pentagonalSet[i] != 0 && hexagonalSet[j] != 0) {
                set2[y][0] = pentagonalSet[i];
                set2[y][1] = hexagonalSet[j];
                y++;
            }
            if(checkCyclic(heptagonalSet[i], octagonalSet[j]) && 
                    heptagonalSet[i] != 0 && octagonalSet[j] != 0) {
                set3[z][0] = heptagonalSet[i];
                set3[z][1] = octagonalSet[j];
                printf("%d %d\n", set3[z][0], set3[z][1]);
                z++;
            }
        }
    }
    
    printf("\n\n\n");/*
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if(checkCyclic(set1[i][1], set2[j][0]) && set1[i][1] != 0 && set2[j][0] != 0) 
                printf("%d %d\n", set1[i][1], set2[j][0]);
        }
    }
    printf("\n");*/
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if(checkCyclic(set2[i][1], set3[j][0]) && set2[i][1] != 0 && set3[j][0] != 0) 
                printf("%d %d\n", set2[i][1], set3[j][0]);
        }
    }/*
    printf("\n");
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if(checkCyclic(set3[i][1], set1[j][0]) && set3[i][1] != 0 && set1[j][0] != 0) 
                printf("%d %d\n", set3[i][1], set1[j][0]);
        }
    }
    printf("\n");*/
//    checkLoops(set1, set2, set3, x, y, z);
    free(set1);
    free(set2);
    free(set3);
}

void checkLoops(int **set1, int **set2, int **set3, int lim1, int lim2, int lim3) {
    int sum = 0;
    for (int i = 0; i < lim1; i++) {
        for (int j = 0; j < lim2; j++) {
            for (int k = 0; k < lim3; k++) {
                if(checkCyclic(set1[i][1], set2[j][0]) &&
                   checkCyclic(set2[j][1], set3[k][0]) &&
                   checkCyclic(set3[k][1], set1[i][0])) {
                   sum = set1[i][0] + set1[i][1] + set2[j][0] +
                         set2[j][1] + set3[k][0] + set3[k][1];
                   printf("%d %d %d %d %d %d\n", set1[i][0], set2[j][0], 
                        set2[j][1], set3[k][0], set3[k][1], set3[i][0]);
                   printf("%d\n", sum);
                }
            }
        }
    }
}

bool checkCyclic(int first, int last) {
    first = first % 100;
    last = last / 100;
    if (first == last) return true;
    else return false;
}

void fillSets() {
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int f = 0;
    for (int i = 0; i < NUM; i++) {
        int tri = triangle(i);
        int squ = square(i);
        int pen = pentagonal(i);
        int hex = hexagonal(i);
        int hep = heptagonal(i);
        int oct = octagonal(i);
        if(tri < UPPER && tri >= LOWER) {
            triangleSet[a] = tri;
            a++;
        }
        if(squ < UPPER && squ >= LOWER) {
            squareSet[b] = squ;
            b++;
        }
        if(pen < UPPER && pen >= LOWER) {
            pentagonalSet[c] = pen;
            c++;
        }
        if(hex < UPPER && hex >= LOWER) {
            hexagonalSet[d] = hex;
            d++;
        }
        if(hep < UPPER && hep >= LOWER) {
            heptagonalSet[e] = hep;
            e++;
        }
        if(oct < UPPER && oct >= LOWER) {
            octagonalSet[f] = oct;
            f++;
        }
    }
}

int triangle(int n) {
    return (n * (n + 1)) / 2;
}

int square(int n) {
    return n * n;
}

int pentagonal(int n) {
    return (n * (3 * n - 1)) / 2;
}

int hexagonal(int n) {
    return n *(2 * n - 1);
}

int heptagonal(int n) {
    return (n * (5 * n - 3)) / 2;
}

int octagonal(int n) {
    return n * (3 * n - 2);
}
