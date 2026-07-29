#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("전달된 개수 : %d\n", argc - 1);
    //arg Argument(아규먼트)의 줄임말로, 
    //우리말로는 ‘인수’ 또는 ‘전달 인자’라고 부릅니다.
    if (argc >= 2)
    {
        printf("제품명 : ");
        for (int i = 1; i < argc; i++)
        {
            printf("%s  ", argv[i]);
        }
    }
    printf("\n");
    return 0;
}
