#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<int> &a, int v) {
    if (a[v] == -1)
        return 0;
    int to = a[v];
    a[v] = -1;
    return 1 + dfs(a, to);
}

void solve(int test) {
    int size;
    cin >> size;

    vector<int> a(size * size);
    for (int &x : a)
        cin >> x;

    int res = (a[0] ? -1 : 0);
    for (int v = 0; v < a.size(); v++)
        if (a[v] != -1 && a[v] != v)
            res += dfs(a, v) + (bool)v;

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