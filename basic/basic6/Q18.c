#include <stdio.h>

int main()
{
    int score[5][5];
    int cnt = 25;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            score[i][j] = cnt--;
            printf("%d\t", score[i][j]);
        }
        printf("\n");
    }
    return 0;
}