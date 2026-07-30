#include <iostream>
#include <memory>
using namespace std;

class Circle
{
public:
    int radius;
    
    Circle():Circle(1){}; // 디폴드 생성자
    Circle(int r){ // 인자가 있는 생성자
        radius = r;
        cout << "반지름 " << radius << "원 생성" << endl;
    }

};

int main()
{
    Circle circle; 
    Circle circle2(30);
    // 객체를 stack 메모리에 생성(자동으로 메모리 관리됨)
    // 일회성 작업에 사용(저장 자체가 안됨)
    Circle* circle3 = new Circle(); 
    Circle* circle4 = new Circle(30);
    // 객체를 heap 메모리에 생성
    delete circle3;
    delete circle4;
    // 삭제 정리 필요
    
    unique_ptr<Circle> circle5 = make_unique<Circle>();
    unique_ptr<Circle> circle5 = make_unique<Circle>(30);
    // 자동 삭제

    return 0;
}
