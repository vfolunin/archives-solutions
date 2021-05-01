#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int len, pointCount;
    if (!(cin >> len >> pointCount))
        return 0;

    int width = len / pointCount;

    vector<int> p(len * 2);
    for (int i = 0; i < pointCount; i++) {
        int x;
        cin >> x;
        p[x]++;
        p[x + len]++;
    }

    for (int i = 1; i < p.size(); i++)
        p[i] += p[i - 1];

    for (int start = 0; start < width; start++) {
        bool ok = 1;
        for (int l = start, r = start + width - 1; ok && l < len; l += width, r += width)
            ok &= p[r] - (l ? p[l - 1] : 0) == 1;
        if (ok) {
            cout << "S\n";
            return 1;
        }
    }

    cout << "N\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}