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

    vector<long long> sticks(stickCount);
    for (long long &stick : sticks)
        cin >> stick;

    sort(sticks.begin(), sticks.end());

    for (int i = 0; i + 2 < stickCount; i++) {
        if (sticks[i] + sticks[i + 1] > sticks[i + 2]) {
            cout << "possible";
            return 0;
        }
    }

    cout << "impossible";
}