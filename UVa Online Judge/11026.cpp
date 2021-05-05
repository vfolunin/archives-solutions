#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n, mod;
    cin >> n >> mod;

    if (!n && !mod)
        return 0;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    vector<vector<long long>> res(n + 1, vector<long long>(n + 1));
    for (int group = 0; group <= n; group++) {
        res[group][0] = 1 % mod;
        for (int take = 1; take <= group; take++)
            res[group][take] = (res[group - 1][take] + res[group - 1][take - 1] * a[group - 1]) % mod;
    }

    cout << *max_element(res[n].begin(), res[n].end()) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}