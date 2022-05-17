#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int ulomek(int *ul, int index, int depth, int *seq, int seqLen) {
    ul[0] = ul[1] + ul[0]; ul[1] = seq[0];
    
    ulomek(ul, index + 1, depth, seq, seqLen);
}

int main() {
    int root = 0;
    int len = 0;
    scanf("%d%d", &root, &len);
    int *seq = calloc(len, sizeof(int));
    for (int i = 0; i < len; i++) scanf("%d", &seq[i]);
    
    int *ul = calloc(2, sizeof(int));
    ul[0] = root; ul[1] = 1;
    int depth = 2;
    ulomek(ul, 0, depth, seq, len);
    
    printf("%d/%d\n", ul[0], ul[1]);
    free(ul);
    free(seq);
    return 0;
}
