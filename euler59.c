#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ASCII lowercase 65-90

int main() {
    FILE *f = malloc(sizeof(FILE));
    f = fopen("euler59.txt", "r");
    int num = 0;
    char dump;
    while (fscanf(f, "%d%c", &num, &dump) > 0) {
        printf("%d%c", num, dump);
    }
    
    fclose(f);
    return 0;
}
