#include<stdio.h>

int main() {
    for (int i = 9; i >= 2; i--) {
        for (int j = 1; j <= 9; j++) {
            printf("%d x %d = %2d\n", i, j, i * j);
       
        }
       
    }

    return 0;
}