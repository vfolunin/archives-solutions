#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1;
    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited);
}

long long binPow(long long x, long long p, long long mod) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1, mod) * x % mod;
    long long r = binPow(x, p / 2, mod);
    return r * r % mod;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> a(2);
    int m = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x > 0].push_back(abs(x));
        m = max(m, abs(x));
    }

    long long res = 0;
    for (auto &a : a) {
        if (a.empty())
            continue;

        sort(a.begin(), a.end());

        vector<long long> d(a.size());
        for (int i = 0; i < a.size(); i++)
            d[i] = 2 * a[i] + (i < k ? 0 : d[i - k]);
        res += d.back();
    }
    res -= m;

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n = 1;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}