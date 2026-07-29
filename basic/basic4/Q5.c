#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // 실행할 때마다 다른 랜덤 값이 나오도록 시드 초기화
    srand((unsigned int)time(NULL));

    printf("오뚜기 카레 제조 공정: 온도 테스트 (3회)\n\n");

    for (int i = 1; i <= 3; i++) {
        // 30부터 50 사이의 랜덤 정수 생성
        // rand() % (최대값 - 최소값 + 1) + 최소값
        int temp = rand() % (50 - 30 + 1) + 30;
        
        printf("[%d차 시도] : %d도\n", i, temp);
    }
    printf("\n-TEST 완료-\n");
    return 0;
}