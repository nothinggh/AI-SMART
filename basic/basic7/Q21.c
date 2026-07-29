#include <stdio.h>

int main()
{
    for (char i = 'A'; i <= 'Z'; i++)
    {
        for (char j = 'A'; j <= 'Z'; j++)
        {
            for (char k = 'A'; k <= 'Z'; k++)
            {
                printf("%c%c%c\n", i, j, k);
            }
        }
    }
    return 0;
}