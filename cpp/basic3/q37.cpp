// Q37) C++로 사칙연산 프로그램을 만드세요.

#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int multiple(int a, int b)
{
    return a * b;
}

double divide(int a, int b)
{
    return (double)a / b;
}

int main()
{
    int a = 10;
    int b = 20;

    cout << "plus결과는 : " << add(a, b) << "입니다." << endl;
    cout << "sub결과는 : " << sub(a, b) << "입니다." << endl;
    cout << "multiple결과는 : " << multiple(a, b) << "입니다." << endl;
    cout << "divide결과는 : " << divide(a, b) << "입니다." << endl;

    return 0;
}