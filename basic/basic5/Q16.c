#include <stdio.h>
#include <string.h>

void print_reverse(char str[]) {
    int len = strlen(str);
    
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main() {
    char str[] = "Battery";

    printf("입력 : %s\n", str);
        printf("출력 : ");
    print_reverse(str);

    return 0;
}
