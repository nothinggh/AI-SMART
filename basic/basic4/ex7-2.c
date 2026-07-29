#include <stdio.h>

int get_num();

int main()
{
    int result =get_num();
    printf("반환값 : %d\n", result);



printf("\n완료\n");
return 0;
}
int get_num()
{
    int num;
    printf("양수 입력 : ");
    scanf("%d\n",&num);
    return 0;
}