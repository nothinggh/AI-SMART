#include <stdio.h>

void print_big() {
    for (int i = 65; i <= 90; i++) {
        printf("%c ", i);
    }
    printf("\n");
}

void print_small() {
    for (int i = 97; i <= 122; i++) {
        printf("%c ", i);
    }
    printf("\n");
}

void print_number() {
    for (int i = 48; i <= 57; i++) {
        printf("%c ", i);
    }
    printf("\n");
}

int main() {
    print_big();
    print_small();
    print_number();
    return 0;
}