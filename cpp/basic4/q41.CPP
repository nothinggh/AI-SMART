// 중복된 값을 제거해 주세요
// set 컨테이너를 활용하여 중복을 제거한 unique한 값을 출력합니다.
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    vector<int> data = {1,2,3,2,2,2,5,1,7,5,5,5};
    set<int> s(data.begin(), data.end()); // 중복 제거 및 정렬

    for (int x : s) cout << x << " ";
    cout << '\n';

    return 0;
}