#include <stdio.h>

int main()
{
    int arr[5];

    // 배열 초기화
    for (int i = 0; i < 5; i++)
    {
        arr[i] = i + 5;
        printf("%d", arr[i]);
    }

    // 배열 출력

    printf("\n");
    return 0;
}
