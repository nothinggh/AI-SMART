#include <stdio.h>

void print_max(int arr[])
{
    int max = arr[0];
    for (int i = 1; i < 7; i++)
    {
        if (arr[i] > max) max = arr[i];
    }
    printf("가장 큰 값 : %d\n", max);
}

int main()
{
    int ary[7] = {4, 5, 8, 1, 2, 3, 7};
    print_max(ary);
    return 0;
}