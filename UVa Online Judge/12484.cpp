#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

inline long long sum(vector<long long> &p, int l, int r) {
    return p[r] - (l ? p[l - 1] : 0);
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    vector<long long> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (i)
            p[i] += p[i - 1];
    }

    vector<vector<long long>> win(2, vector<long long>(n));

    for (int i = 0; i < n; i++)
        win[0][i] = sum(p, i, i);

    for (int len = 2; len <= n; len++) {
        for (int l = 0, r = len - 1; r < n; l++, r++)
            win[1][l] = sum(p, l, r) - min(win[0][l], win[0][l + 1]);
        win[0].swap(win[1]);
    }

    cout << win[0][0] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}