#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int sum(vector<int> &p, int l, int r) {
    if (l > r)
        return 0;
    return p[r] - (l ? p[l - 1] : 0);
}

bool solve() {
    int aSize;
    cin >> aSize;

    if (!aSize)
        return 0;

    vector<int> pa(aSize);
    map<int, int> aPos;

    for (int i = 0; i < aSize; i++) {
        cin >> pa[i];
        aPos[pa[i]] = i;
        if (i)
            pa[i] += pa[i - 1];
    }

    int bSize;
    cin >> bSize;

    vector<int> pb(bSize);
    pair<int, int> lastCommon = { -1, -1 };
    int res = 0;

    for (int i = 0; i < bSize; i++) {
        cin >> pb[i];
        if (aPos.count(pb[i])) {
            int aSum = sum(pa, lastCommon.first + 1, aPos[pb[i]] - 1);
            int bSum = sum(pb, lastCommon.second + 1, i - 1);
            res += max(aSum, bSum) + pb[i];
            lastCommon = { aPos[pb[i]], i };
        }
        if (i)
            pb[i] += pb[i - 1];
    }

    int aSum = sum(pa, lastCommon.first + 1, aSize - 1);
    int bSum = sum(pb, lastCommon.second + 1, bSize - 1);
    res += max(aSum, bSum);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}