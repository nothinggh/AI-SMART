#include <stdio.h>

int main()
{
    FILE *fp;
    char str[80] ="banana";
    printf("문자열을 입력하세요: ");
    fgets(str, sizeof(str), stdin);


    fp=fopen("c.txt","w");

    int i=0;
    while(str[i] != '\0'){
        fputc(str[i], fp);
        printf("%c", str[i]);
        i++;

    }
fclose(fp);
return 0;
}