#include <iostream>
using namespace std;

double area(int r); // 함수 선언
double area(int r)
{
    return 3.14 * r * r;
}

int main()
{
    int n = 3;
    char c = '#';

    cout << "n + 5 = " << n + 5 << endl;
    cout << "면적:" << area(5) << endl;

    return 0;
}