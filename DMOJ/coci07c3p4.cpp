#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int pointCount;
    cin >> pointCount;

    vector<pair<int, int>> points(pointCount);
    unordered_map<int, int> xCount, yCount;

    for (auto &[x, y] : points) {
        cin >> x >> y;

        xCount[x]++;
        yCount[y]++;
    }

    long long res = 0;
    for (auto &[x, y] : points)
        res += (xCount[x] - 1LL) * (yCount[y] - 1LL);

    cout << res;
}