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
    for (auto &[deadline, penalty] : pairs)
        cin >> deadline >> penalty;

    sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first < b.first;
    });

    set<int> slots;
    for (int i = 1; i <= pairCount; i++)
        slots.insert(i);

    long long res = 0;
    for (auto &[deadline, penalty] : pairs) {
        auto it = slots.upper_bound(deadline);
        if (it == slots.begin())
            res += penalty;
        else
            slots.erase(--it);
    }

    cout << res;
}