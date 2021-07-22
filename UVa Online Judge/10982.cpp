#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    set<int> a, b;
    for (int v = 0; v < vertexCount; v++) {
        int aCost = 0, bCost = 0;
        for (int to : graph[v]) {
            aCost += a.count(to);
            bCost += b.count(to);
        }
        if (aCost < bCost)
            a.insert(v);
        else
            b.insert(v);
    }

    cout << "Case #" << test << ": " << a.size() << "\n";
    for (auto it = a.begin(); it != a.end(); it++)
        cout << *it + 1 << (next(it) != a.end() ? " " : "\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}