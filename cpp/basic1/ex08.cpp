#include <iostream>
#include <memory>
using namespace std;

class Circle{
public:
    int radius;

    Circle():Circle(1){}; //디폴트 생성자 -> 위임생성자 문법을 통해 만들었다.
    Circle(int r){ //인자가 있는 생성자 -> 타겟생성자
        radius = r;
        cout << "반지름 " << radius << " 원 생성" << endl;
    };
    ~Circle(){
        cout << "소멸자 실행" << endl;
    }
};

int main()
{
    Circle circle;
    Circle circle2(30);
    return 0;
}
// ddd
