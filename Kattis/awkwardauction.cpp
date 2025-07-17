#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int l, int r, int penalty) {
    static vector<vector<int>> memo(401, vector<int>(401, -1));
    int &res = memo[l][r];
    if (res != -1)
        return res;

    if (l == r)
        return res = l;

    res = 1e9;
    for (int i = l; i <= r; i++) {
        int cur = i;
        if (l < i)
            cur = max(cur, i + rec(l, i - 1, penalty));
        if (i < r)
            cur = max(cur, penalty + rec(i + 1, r, penalty));
        res = min(res, cur);
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int r, penalty;
    cin >> r >> penalty;

    cout << rec(1, r, penalty);
}