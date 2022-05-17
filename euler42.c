#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *get_words(char *c, int size);
bool triangular(int n, int counter);

int main() {
    FILE *f = fopen("euler42.txt", "r");
    char *c = (char*)calloc(17000, sizeof(char));
    fscanf(f, "%s", c);
    int len = 0;
    int size = 1;
    while(c[len] != '\0') {
        len++;
        if(c[len] == ',') size++;
    }
    c = realloc(c, (len + 1) * sizeof(char));

    int count = 0;
    int *words = get_words(c, size);
    for(int i = 0; i < size; i++) {
        if(triangular(words[i], 1)) count++;
    }
    printf("%d\n", count);
    return 0;
}

int *get_words(char *c, int size) {
    int *words = (int*)calloc(size, sizeof(int));
    int j = 0; 
    int sum = 0;
    for(int i = 0;; i++) {
        if(c[i] >= 'A' && c[i] <= 'Z') {
            sum += c[i] - 'A' + 1;
        }
        else if(c[i] == ',') {
            words[j] = sum;
            sum = 0;
            j++;
        }
        else if(c[i] == '\0') {
            words[j] = sum;
            break;
        }
    }
    return words;
}

bool triangular(int n, int counter) {
    int f = (int)(counter * (counter + 1)) / 2;
    if(n < f) return false;
    else if(n == f) return true;
    else return triangular(n, counter + 1);
}
