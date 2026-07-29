#include <stdio.h>
#include <string.h>

int main()
{
    char str[80];

    fgets(str, sizeof(str), stdin); // apple jam
    printf("현재 글자수 : %d\n", strlen(str));

    return 0;
}