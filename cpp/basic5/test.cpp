#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    string c = "test, abc, apple, computer, pipe, valve";

    // 문자열의 각 문자를 대문자로 직접 변환
    for (char &ch : c)
        ch = toupper(ch);

    cout << "결과 : " << c << endl;
    return 0;
}