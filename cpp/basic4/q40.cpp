// 문자열 뒤짚어 출력하기
// Hello
// STL 함수를 이용해서 작업하세요~~!

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s = "hello";
    reverse(s.begin(), s.end());
    cout << s << endl;
    
    return 0;
}