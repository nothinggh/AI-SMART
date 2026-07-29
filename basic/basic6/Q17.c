#include <stdio.h>
#include <string.h>

int main()
{
    char name[50];
    char date[50];
    char lot[100];

    printf("제품명: ");
    scanf("%s", name);

    printf("생산일: ");
    scanf("%s", date);

    strcpy(lot, name);
    strcat(lot, "_");
    strcat(lot, date);

    printf("출력: %s\n", lot);

    return 0;
}