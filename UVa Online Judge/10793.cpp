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

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));
    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 0;
    for (int i = 0; i < edgeCount; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        dist[a - 1][b - 1] = dist[b - 1][a - 1] = min(dist[a - 1][b - 1], d);
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    int res = -1;
    for (int v = 0; v < vertexCount; v++) {
        if (dist[v][0] != dist[v][1] || dist[v][0] != dist[v][2] ||
            dist[v][0] != dist[v][3] || dist[v][0] != dist[v][4])
            continue;
        int cur = *max_element(dist[v].begin(), dist[v].end());
        if (cur != 1e9 && (res == -1 || res > cur))
            res = cur;
    }

    cout << "Map " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}