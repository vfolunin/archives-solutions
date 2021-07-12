#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int qMask, int aMask, int paramCount, vector<int> &objs, vector<vector<int>> &memo) {
    int &res = memo[qMask][aMask];
    if (res != -1)
        return res;

    int k = 0;
    for (int obj : objs)
        k += (obj & qMask) == aMask;

    if (k == 1)
        return res = 0;

    res = 1e9;
    for (int q = 0; q < paramCount; q++) {
        if (qMask & (1 << q))
            continue;
        int nqMask = qMask | (1 << q);
        int naMask = aMask | (1 << q);
        int r0 = rec(nqMask, aMask, paramCount, objs, memo);
        int r1 = rec(nqMask, naMask, paramCount, objs, memo);
        res = min(res, 1 + max(r0, r1));
    }
    return res;
}

bool solve() {
    int paramCount, objCount;
    cin >> paramCount >> objCount;

    if (!paramCount && !objCount)
        return 0;

    vector<int> objs(objCount);
    for (int &obj : objs) {
        string s;
        cin >> s;
        for (int i = paramCount - 1; i >= 0; i--)
            obj |= (s[i] - '0') << i;
    }

    vector<vector<int>> memo(2048, vector<int>(2048, -1));
    int res = rec(0, 0, paramCount, objs, memo);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}