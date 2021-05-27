#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long sum(vector<long long> &p, int l, int r) {
    return p[r] - (l ? p[l - 1] : 0);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<long long> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (i)
            p[i] += p[i - 1];
    }

    vector<vector<long long>> win(n, vector<long long>(n));

    for (int i = 0; i < n; i++)
        win[i][i] = sum(p, i, i);

    for (int len = 2; len <= n; len++)
        for (int l = 0, r = len - 1; r < n; l++, r++)
            win[l][r] = sum(p, l, r) - min(win[l + 1][r], win[l][r - 1]);

    cout << win[0][n - 1];
}