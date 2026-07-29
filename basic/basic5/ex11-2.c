#include <stdio.h>

int main()
{
    char ch1, ch2;
    scanf(" %c %c", &ch1, &ch2); 
    // 2개의 문자를 연속 입력, 문자열로 바꾸면 문제 해결
    printf("[%c%c]\n", ch1, ch2); 
    // 입력된 문자 출력

    return 0;
}