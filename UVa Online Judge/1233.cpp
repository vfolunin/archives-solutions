#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int boxCapacity, vertexCount;
    cin >> boxCapacity >> vertexCount;
    vertexCount++;

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));

    int edgeCount;
    cin >> edgeCount;

    for (int i = 0; i < edgeCount; i++) {
        int to;
        cin >> to;
        dist[0][to] = 0;
    }

    for (int v = 1; v < vertexCount; v++) {
        int edgeCount;
        cin >> edgeCount;

        for (int i = 0; i < edgeCount; i++) {
            int w, to;
            cin >> w >> to;
            dist[v][to] = min(dist[v][to], w);
        }
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    int cycleWeight = dist[0][0];
    int cycleCount = boxCapacity / (cycleWeight - 1);
    int subtractedCount = 0;
    while ((cycleCount - subtractedCount) * (cycleWeight - 1) + cycleWeight >= boxCapacity)
        subtractedCount++;
    int res = cycleCount - subtractedCount + 1;

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