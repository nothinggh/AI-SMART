#include <stdio.h>

int main()
{
    int ary[7] = {4, 5, 8, 1, 2, 3, 7};
    int min = ary[0];

    for (int i = 1; i < 7; i++) {
        if (ary[i] < min) {
            min = ary[i];
        }
    }

    printf("최소값: %d\n", min);

    return 0;
}