#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount));
    vector<vector<int>> next(vertexCount, vector<int>(vertexCount, -1));
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            cin >> dist[a][b];
            if (dist[a][b] == 1e5)
                dist[a][b] = 1e9;
            else
                next[a][b] = b;
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
            vector<int> cycle = { v };
            for (int cycleV = next[v][v]; cycleV != v; cycleV = next[cycleV][v])
                cycle.push_back(cycleV);
            cycle.push_back(v);

            cout << "YES\n" << cycle.size() << "\n";
            for (int cycleV : cycle)
                cout << cycleV + 1 << " ";
            return 0;
        }
    }

    cout << "NO";
}