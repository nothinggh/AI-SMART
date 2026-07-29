#include <stdio.h>

int main()
{
    int a = 10, b = 20;
    int temp;

    printf("a b : %d %d\n", a, b);
    {
        int a;
        a = 100;
        printf("temp: %d\n", a);
    }

    printf("temp: %d\n", temp);
    return 0;
}