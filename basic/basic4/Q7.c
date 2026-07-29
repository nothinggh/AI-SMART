#include <stdio.h>

int main() {
    int count = 0;
    int input;

    while (1) { //for(;;) while 같음
        printf("추가 생산량 입력: ");
        scanf("%d", &input);

        count += input; 
        printf("현재 누적 생산량: %d개\n", count);

        if (count >= 1000) {
            printf("목표 생산량(1000개) 달성! 프로그램 종료.\n");
            break; 
        }
    }

    return 0;
}