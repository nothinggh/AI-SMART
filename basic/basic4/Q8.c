#include <stdio.h>

void inputSize(int *w, int *h) {
    printf("가로 입력:");
    scanf("%d", w);
    printf("세로 입력:");
    scanf("%d", h);
}

void printArea(int w, int h) {
    int area = w * h;
    printf("사각형의 넓이는 %d입니다.\n", area);
    printf("\n완료\n");
    
}

int main() {
    int width = 0;
    int height = 0;
    inputSize(&width, &height);
    
    printArea(width, height);
    return 0;
}