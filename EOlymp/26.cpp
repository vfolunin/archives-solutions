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
    for (auto &[a, b] : pairs)
        cin >> a;
    for (auto &[a, b] : pairs)
        cin >> b;

    sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
        return min(a.first, b.second) < min(a.second, b.first);
    });

    int ta = 0, tb = 0;
    for (auto &[a, b] : pairs) {
        ta += a;
        tb = max(ta, tb) + b;
    }

    cout << tb;
}