#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(string &a, int al, int ar,
        string &b, int bl, int br,
        vector<vector<vector<vector<int>>>> &memo) {
    if (al > ar || bl > br)
        return 0;

    int &res = memo[al][ar][bl][br];
    if (res != -1)
        return res;

    if (al == ar) {
        int pos = b.find(a[al], bl);
        return res = (pos != -1 && pos <= br);
    }
    if (bl == br) {
        int pos = a.find(b[bl], al);
        return res = (pos != -1 && pos <= ar);
    }

    if (a[al] == a[ar] && a[al] == b[bl] && a[al] == b[br])
        return res = 2 + rec(a, al + 1, ar - 1, b, bl + 1, br - 1, memo);

    res = max(res, rec(a, al + 1, ar, b, bl, br, memo));
    res = max(res, rec(a, al, ar - 1, b, bl, br, memo));
    res = max(res, rec(a, al, ar, b, bl + 1, br, memo));
    res = max(res, rec(a, al, ar, b, bl, br - 1, memo));
    return res;
}

void solve(int test) {
    string a, b;
    cin >> a >> b;

    vector<vector<vector<vector<int>>>> memo(a.size(),
        vector<vector<vector<int>>>(a.size(),
            vector<vector<int>>(b.size(), vector<int>(b.size(), -1))
        )
    );
    int res = rec(a, 0, a.size() - 1, b, 0, b.size() - 1, memo);

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}