#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    char temp[100];

    printf("제품명 입력 : ");
    fgets(temp, sizeof(temp), stdin);

    temp[strcspn(temp, "\n")] = '\0'; //strcspn 삭제함수

    //동적할당
    char *product =
        (char *)malloc(strlen(temp) + 1); //배열공간 만들기

    strcpy(product, temp);
    printf("저장된 제품명 : %s\n", product);
    free(product);
    return 0;
}