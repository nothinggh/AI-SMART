// 다음 숫자들을 정렬하여 출력하라.
// 정렬 되지 않은 다음의 수들이 있다.
// 이를 STL 컨테이너 자료구조에 넣은 후 정렬하여 출력해 보자.
// 30 10 50 20 1 3 5
// 1 3 5 10 30 50


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
vector<int> v = {30, 10, 50, 20, 1, 3, 5};

    sort(v.begin(), v.end());

    for (int n : v)
        cout << n << ' ';
    cout << '\n';

    return 0;
}