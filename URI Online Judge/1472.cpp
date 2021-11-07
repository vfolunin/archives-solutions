#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int pointCount;
    if (!(cin >> pointCount))
        return 0;

    vector<int> arc(pointCount);
    int side = 0;
    for (int &a : arc) {
        cin >> a;
        side += a;
    }

    if (side % 3) {
        cout << "0\n";
        return 1;
    }
    side /= 3;

    int res = 0;
    for (int i = 0, ai = 0, bi = 0, aLen = 0, bLen = 0; i < pointCount; i++) {
        for (; aLen < side; ai = (ai + 1) % pointCount)
            aLen += arc[ai];

        for (; bLen < 2 * side; bi = (bi + 1) % pointCount)
            bLen += arc[bi];

        res += aLen == side && bLen == 2 * side;
        aLen -= arc[i];
        bLen -= arc[i];
    }

    cout << res / 3 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}