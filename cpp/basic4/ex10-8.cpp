#include <iostream>
#include <vector>
using namespace std;

// 원소에 정수를 입력하고 값을 연산하라.

int main()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator it; // 이터레이터 변수 생성

    for (it = v.begin(); it != v.end(); it++)
    {
        {
            cout << *it << " ";
        }
        cout << endl;

        v[0] = 10;
        cout << v[0] << endl;
        return 0;
    }
}