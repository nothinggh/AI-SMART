#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char lot[100];
    int count = 0;

    printf("문자열을 입력하세요: ");
    scanf("%99s", lot);

    int length = strlen(lot);

    for (int i = 0; i < length; i++)
    {
        if (isupper(lot[i]))
        {
            count++;
        }
    }

    printf("대문자 개수 : %d\n", count);
    return 0;
}