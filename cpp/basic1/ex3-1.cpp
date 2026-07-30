#include <iostream>
using namespace std;

class Circle
{
public:
    int radius;
    double getArea();
};

double Circle::getArea()
{
    return 3.14 * radius * radius;
}

int main()
{
    Circle donut; // 객체생성 stack 에 생성
    donut.radius = 1;
    double area = donut.getArea();
    cout << "면적은 : " << area << endl;

    return 0;
}
