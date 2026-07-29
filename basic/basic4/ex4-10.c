#include <stdio.h>

int main()
{
    int a=10, b=20;
    int res=2;

    a += 20;              // a=a+20;
    res = res * (b + 10); // res=res*(b+10);
                          // res*=b+10; // res=res*(b+10);

    printf("%d\n", a);
    printf("%d\n", res);

    return 0;
}