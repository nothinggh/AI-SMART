#include <stdio.h>

int main()
{
    int age;
    char name[20];

    printf("나이 입력 : ");
   // scanf("%d", &age); //엔터 문제
    scanf("%d%*c", &age); //숫자 입력 후 남는 엔터 \n 읽어서 버림
    

    printf("이름 입력 : ");
    fgets(name, sizeof(name), stdin);
    printf("나이: %d, 이름: %s\n", age, name);

    return 0;
}