#include <iostream>
#include <vector>
using namespace std;

// 원소에 정수를 입력하고 값을 연산하라.

int main()
{
    vector<int> v;
    // 값 입력
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    // 출력
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    // 벡터의 첫번째 요소값을 10으로 변경
    v[0] = 10;
    cout << "v[0]:" << v.at(0) << endl;

    return 0;
}