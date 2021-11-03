#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int root, vertexCount, edgeCount;
    cin >> root >> vertexCount >> edgeCount;

    map<pair<int, int>, int> edges;
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        edges[{a, b}]++;
    }

    int res = 0;
    for (auto &[edge, count] : edges)
        res += count + count % 2;

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}