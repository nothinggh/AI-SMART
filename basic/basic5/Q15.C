#include <stdio.h>

void my_strcpy(char *dest, const char *src)
{
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int main()
{
    char origin[] = "Battery";
    char target[20];

    my_strcpy(target, origin);

    printf("%s\n", target);

    return 0;
}
