#include <stdio.h>

int main()
{
    int res;
    char ch;

    while (1) //무한
    {
        res = scanf("%c", &ch);
        if (res == -1) break;
        printf("%d ", ch);
    }

    return 0;
}