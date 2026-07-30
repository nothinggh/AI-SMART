#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> nums = {10, 3, 7, 20, 15};
    int max_value = *max_element(nums.begin(), nums.end());
    cout << "Maximum value: " << max_value << endl;
    return 0;
}