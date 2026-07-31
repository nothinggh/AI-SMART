// 연산자 오버로딩
#include <iostream>
using namespace std;

class Power
{
public:
    int kick;
    int punch;

    Power(int kick = 0, int punc = 0)
    {
        this->kick = kick;
        this->punch = punc;
    }
    void show()
    {
        cout << "kick=" << kick << ", " << "punch=" << punch << endl;
    }
    // 연산자 오버로딩
    Power operator+(const Power &other) const
    {
        return Power(this->kick + other.kick, this->punch + other.punch);
    }
};

int main()
{
    Power hong(3, 3); // 객체 생성
    Power lee(5, 5);
    hong.show();
    lee.show();

    Power hero = hong + lee;
    hero.show();
    return 0;
}