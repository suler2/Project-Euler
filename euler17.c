#include <stdio.h>

enum tens{
    zero, one, two, three, four, five,
    six, seven, eight, nine
};

enum teens {
    ten = 10, eleven, twelve, thirteen, fourteen, fifteen,
    sixteen, seventeen, eighteen, nineteen
};

int getNumbers(int n);
int to_ten(int n);
int teen(int n);
int to_hundred(int n);
int to_thousand(int n);

int main() {
    int count = 0;
    int n = 0;
    for (int i = 1; i < 1000; i++) {
        count += getNumbers(i);
//        printf("i = %d, ct = %d\n", i, count);
    }
    count += 11; //one thousand
    printf("%d\n", count);
    return 0;
}

int getNumbers(int n) {
    if(n < 10) return to_ten(n);
    else if(n >= 10 && n < 20) return teen(n);
    else if(n >= 20 && n < 100) return to_hundred(n / 10) + getNumbers(n % 10);
    else if(n >= 100 && n < 1000 && n % 100 != 0) return to_thousand(n / 100) + getNumbers(n % 100);
    else if(n >= 100 && n < 1000 && n % 100 == 0) return 7 + to_ten(n / 100);
    else return 0;
}

int to_ten(int n) {
    switch(n) {
        case zero: return 0;
        case one: return 3;
        case two: return 3;
        case three: return 5;
        case four: return 4;
        case five: return 4;
        case six: return 3;
        case seven: return 5;
        case eight: return 5;
        case nine: return 4;
        default: return 0;
    }
}

int teen(int n) {
    switch(n) {
        case ten: return 3;
        case eleven: return 6;
        case twelve: return 6;
        case thirteen: return 8;
        case fourteen: return 8;
        case fifteen: return 7;
        case sixteen: return 7;
        case seventeen: return 9;
        case eighteen: return 8;
        case nineteen: return 8;
        default: return 0;
    }
}

int to_hundred(int n) {
    switch(n) {
        case 2: return 6;
        case 3: return 6;
        case 4: return 5;
        case 5: return 5;
        case 6: return 5;
        case 7: return 7;
        case 8: return 6;
        case 9: return 6;
        default: return 0;
    }
}

int to_thousand(int n) {
    if(n % 10)
    return 10 + to_ten(n);
}
