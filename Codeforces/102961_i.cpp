#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int stickCount;
    cin >> stickCount;

    vector<int> stickLength(stickCount);
    for (int &length : stickLength)
        cin >> length;

    nth_element(stickLength.begin(), stickLength.begin() + stickCount / 2, stickLength.end());
    int medianLength = stickLength[stickCount / 2];

    long long res = 0;
    for (int length : stickLength)
        res += abs(length - medianLength);

    cout << res;
}