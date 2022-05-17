#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int rectangles(int ixa, int ixb, int a, int b) {
    int formula = (a - ixa + 1) * (b - ixb + 1);
//    printf("%d, %d, %d\n", ixa, ixb, formula);
    return formula;
}

int getCount(int ixa, int ixb, int a, int b, bool **visited) {
    visited[ixa][ixb] = true;
    int count = 0;
    if(ixa > a && ixb > b) count++;
    else {
        count += rectangles(ixa, ixb, a, b);
        if(ixa < a && !visited[ixa + 1][ixb]) 
            count += getCount(ixa + 1, ixb, a, b, visited);
        if(ixb < b && !visited[ixa][ixb + 1]) 
            count += getCount(ixa, ixb + 1, a, b, visited);
    }
    return count;
}

int main() {
    int res = INT_MAX;
    int area = 0;
    int size = 100;
    int count = 0;
    bool **visited = calloc(1001, sizeof(bool));
    for (int i = 0; i < 1001; i++) visited[i] = calloc(1001, sizeof(bool));
    for (int a = 3; a < size; a++) {
        for (int b = 3; b <= a; b++) {
            for (int i = 0; i < a + 1; i++)
                for (int j = 0; j < b + 1; j++)
                    visited[i][j] = false;
//            printf("%d %d\n", a, b);
            count = getCount(1, 1, a, b, visited);
            printf("%d %d %d\n", a, b, count);
            int diff = 2000000 - count;
            if(diff < 0) diff = -diff;
//            printf("diff = %d, res = %d\n", diff, res);
            if(diff < res) {
                res = diff;
                area = a * b;
            }
//            else break;
        }
    }
    free(visited);
    printf("%d, %d\n", res, area);
    return 0;
}
