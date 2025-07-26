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

    int pairCount;
    cin >> pairCount;

    vector<pair<int, int>> pairs(pairCount);
    for (auto &[time, index] : pairs)
        cin >> time >> index;

    sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });

    int curTime = 1;
    long long res = 0;
    for (auto &[time, index] : pairs) {
        res += max(time - curTime, 0);
        curTime = max(curTime, time) + 1;
    }

    cout << res;
}