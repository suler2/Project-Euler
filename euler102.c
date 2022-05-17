#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Tocka {
    int x;
    int y;
}Tocka;

typedef struct _Trikotnik {
    Tocka** t;
}Trikotnik;

void read(Trikotnik **trikotniki);
int izracunaj(Trikotnik** trikotniki, int index);
int posamezen(Trikotnik* trikotnik);

int main() {
    Trikotnik **trikotniki = malloc(1000 * sizeof(Trikotnik*));
    read(trikotniki);
    int count = 0;
    count = izracunaj(trikotniki, 0);
    printf("%d\n", count);
    free(trikotniki);
    return 0;
}

int getInt(char* line, int start, int end) {
    int cifra = 0;
    bool neg = false;
    for (int i = start; i < end; i++) {
        if(line[i] == '-') neg = true;
        else cifra = cifra * 10 + line[i] - '0';
    }
    if(neg) return -cifra;
    else return cifra;
}

void read(Trikotnik **trikotniki) {
    FILE *f = fopen("euler102.txt", "r");
    char* line = calloc(100, sizeof(char));
    int index = 0;
    while(fgets(line, 100, f)) {
        trikotniki[index] = malloc(sizeof(Trikotnik));
        trikotniki[index]->t = malloc(3 * sizeof(Tocka*));
        for (int i = 0; i < 3; i++)
            trikotniki[index]->t[i] = malloc(sizeof(Tocka));
        int len = strlen(line);
        int prev = 0;
        int count = 0;
        for (int i = 0; i < len; i++) {
            if(line[i] == ',') {
                count++;
                switch(count) {
                    case 1:
                        trikotniki[index]->t[0]->x = getInt(line, 0, i);
                        break;
                    case 2:
                        trikotniki[index]->t[0]->y = getInt(line, prev, i);
                        break;
                    case 3:
                        trikotniki[index]->t[1]->x = getInt(line, prev, i);
                        break;
                    case 4:
                        trikotniki[index]->t[1]->y = getInt(line, prev, i);
                        break;
                    case 5:
                        trikotniki[index]->t[2]->x = getInt(line, prev, i);
                        trikotniki[index]->t[2]->y = getInt(line, i + 1, len - 1);
                        break;
                }
                prev = i + 1;
            }
        }
        index++;
        
    }
    fclose(f);
}

/*
Vektorski produkt, ce so vsi negativni oz pozitivni, potem lezi v trikotniku
xp in yp je 0, ker sta to koordinati izhodisca
(xa-xp)*(yb-yp) – (ya-yp)*(xb-xp)
(xb-xp)*(yc-yp) – (yb-yp)*(xc-xp)
(xc-xp)*(ya-yp) – (yc-yp)*(xa-xp) 
*/
int izracunaj(Trikotnik** trikotniki, int index) {
    int count = 0;
    if(index == 1000) return 0;
    else {
        count += posamezen(trikotniki[index]) + izracunaj(trikotniki, index + 1);
    }
    return count;
}

int posamezen(Trikotnik* trikotnik) {
    int count = 0;
    if(trikotnik->t[0]->x * trikotnik->t[1]->y 
       - trikotnik->t[0]->y * trikotnik->t[1]->x > 0)count++;
    else count--;
    if(trikotnik->t[1]->x * trikotnik->t[2]->y 
       - trikotnik->t[1]->y * trikotnik->t[2]->x > 0)count++;
    else count--;
    if(trikotnik->t[2]->x * trikotnik->t[0]->y 
       - trikotnik->t[2]->y * trikotnik->t[0]->x > 0)count++;
    else count--;
    if(count == 3 || count == -3) return 1;
    else return 0;
}
