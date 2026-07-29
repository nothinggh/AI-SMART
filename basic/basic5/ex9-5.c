#include <stdio.h>

int main()
{
    char ch;
    double db;
    int in;

    char *pc = &ch;
    double *pd = &db;
    int *pi=&in;

    printf("ch변수의 자료형의 크기: %zu\n", sizeof(ch));
    printf("db변수의 자료형의 크기: %zu\n", sizeof(db));
    printf("in변수의 자료형의 크기: %zu\n", sizeof(in));

    printf("ch 포인터 변수 자료형의 크기: %zu\n", sizeof(&ch));
    printf("db 포인터 변수 자료형의 크기: %zu\n", sizeof(&db));
    printf("in 포인터 변수 자료형의 크기: %zu\n", sizeof(&in));

    return 0;
}