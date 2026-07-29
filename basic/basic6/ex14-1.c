#include <stdio.h>

int main()
{
    int score[3][4];
    int cnt = 1;
    // 2차원 배열 초기화
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++){
            score[i][j] = cnt++;
            printf("\n");
        }
        return 0;
    }
}
    //}
    // 2차원 배열 출력
    /* for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++)
            printf("%d", score[i][j]);
        }
        printf("\n");
    return 0;
} */