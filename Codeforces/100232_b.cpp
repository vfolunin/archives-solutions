#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("negcycle.in", "r", stdin);
    freopen("negcycle.out", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));
    vector<vector<int>> next(vertexCount, vector<int>(vertexCount, -1));

    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 0;

    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            int weight;
            cin >> weight;

            if (weight != 1e5 && dist[a][b] > weight) {
                dist[a][b] = weight;
                next[a][b] = b;
            }
        }
    }

    for (int v = 0; v < vertexCount; v++) {
        for (int a = 0; a < vertexCount; a++) {
            for (int b = 0; b < vertexCount; b++) {
                if (dist[a][v] != 1e9 && dist[v][b] != 1e9 && dist[a][b] > dist[a][v] + dist[v][b]) {
                    dist[a][b] = max<int>(dist[a][v] + dist[v][b], -1e9);
                    next[a][b] = next[a][v];
                }
            }
        }
    }

    for (int v = 0; v < vertexCount; v++) {
        if (dist[v][v] < 0) {
            for (int i = 0; i < vertexCount; i++)
                v = next[v][v];

            vector<int> cycle = { v };
            for (int cycleV = next[v][v]; cycleV != v; cycleV = next[cycleV][v])
                cycle.push_back(cycleV);

            cout << "YES\n" << cycle.size() << "\n";
            for (int v : cycle)
                cout << v + 1 << " ";
            return 0;
        }
    }

    cout << "NO";
}