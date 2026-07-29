#include <stdio.h>

int get_gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    int gcd = get_gcd(a, b);
    long long lcm = ((long long)a * b) / gcd;

    printf("%d %lld\n", gcd, lcm);

    return 0;
}