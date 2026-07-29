#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // 1.seed 값 설정
    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", rand() %10 + 1);
    }
    printf("\n\n-완료-\n"); // \n 줄바꿈
    return 0;
}