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

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<long long> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (i)
            p[i] += p[i - 1];
    }

    vector<vector<long long>> firstScore(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
        firstScore[i][i] = sum(p, i, i);
    for (int len = 2; len <= n; len++) {
        for (int l = 0, r = l + len - 1; r < n; l++, r++) {
            firstScore[l][r] = sum(p, l, r);
            for (int i = l; i < r; i++)
                firstScore[l][r] = max(firstScore[l][r], sum(p, l, r) - firstScore[i + 1][r]);
            for (int i = l + 1; i <= r; i++)
                firstScore[l][r] = max(firstScore[l][r], sum(p, l, r) - firstScore[l][i - 1]);
        }
    }

    cout << 2 * firstScore[0][n - 1] - sum(p, 0, n - 1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}