#include <stdio.h>

int main()
{
    char grade;
    char name[20];

    printf("학점을 입력하세요 : ");
    scanf("%c", &grade);
    printf("이름을 입력하세요 : ");
    scanf("%s", name);

    printf("%s의 학점은 %c입니다.\n", name, grade);

    return 0;
}