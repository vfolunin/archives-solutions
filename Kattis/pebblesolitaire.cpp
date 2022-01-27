#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int mask) {
    static vector<int> memo(1 << 12, -1);
    if (memo[mask] != -1)
        return memo[mask];

    int res = 0;
    for (int bit = 0; bit < 12; bit++)
        res += (bool)(mask & (1 << bit));

    for (int a = 0, b = 1, c = 2; c < 12; a++, b++, c++)
        if ((mask & (1 << b)) && (bool)(mask & (1 << a)) != (bool)(mask & (1 << c)))
            res = min(res, rec(mask ^ (1 << a) ^ (1 << b) ^ (1 << c)));

    return memo[mask] = res;
}

void solve() {
    string s;
    cin >> s;

    int mask = 0;
    for (int bit = 0; bit < 12; bit++)
        if (s[bit] == 'o')
            mask |= 1 << bit;

    cout << rec(mask) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}