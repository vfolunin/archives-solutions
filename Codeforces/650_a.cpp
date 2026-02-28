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

    int pointCount;
    cin >> pointCount;

    map<int, int> xCount, yCount;
    map<pair<int, int>, int> pairCount;

    for (int i = 0; i < pointCount; i++) {
        int x, y;
        cin >> x >> y;

        xCount[x]++;
        yCount[y]++;
        pairCount[{ x, y }]++;
    }

    long long res = 0;
    for (auto &[x, count] : xCount)
        res += 1LL * count * (count - 1) / 2;
    for (auto &[y, count] : yCount)
        res += 1LL * count * (count - 1) / 2;
    for (auto &[pair, count] : pairCount)
        res -= 1LL * count * (count - 1) / 2;

    cout << res;
}