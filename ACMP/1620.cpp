#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> readTime() {
    int hours, minutes;
    char colon;
    cin >> hours >> colon >> minutes;

    return { hours, minutes };
}

int getDiff(int h1, int m1, int h2, int m2) {
    int dh = abs(h1 - h2);
    int dm = abs(m1 - m2);
    return min(dh, 24 - dh) + min(dm, 60 - dm);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int clockCount;
    cin >> clockCount;

    vector<pair<int, int>> clocks(clockCount);
    for (pair<int, int> &clock : clocks)
        clock = readTime();

    auto [targetH, targetM] = readTime();
    int res = 1 + getDiff(0, 0, targetH, targetM);

    for (auto [h, m] : clocks)
        res = min(res, getDiff(h, m, targetH, targetM));

    cout << res;
}