#include <stdio.h>

int main() {
    int celsius;
    double fahrenheit;
    printf("섭씨 온도를 입력하세요 : ");
    scanf("%d", &celsius);


    fahrenheit = (9.0 / 5.0) * celsius + 32;

    printf("화씨 온도 : %.1lf\n", fahrenheit);
    
    return 0;
}