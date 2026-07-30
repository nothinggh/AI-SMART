// Map 컨테이너 연습
// 키를 넣으면 값을 주는 자료구조가 map이다.
// Kim 90
// Lee  80
// Park 95
// 위 데이터를 map으로 만들고 이름을 입력하면 점수를 출력합니다.

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    map<string, int> scores;
    scores["Kim"] = 90;
    scores["Lee"] = 80;
    scores["Park"] = 95;

    string name;
    if (!(cin >> name)) return 0;

    auto it = scores.find(name);
    if (it != scores.end()) cout << it->second << '\n';
    else cout << "Not found" << '\n';

    return 0;
}