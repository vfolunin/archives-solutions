#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int vertexCount, edgeCount, queryCount;
    cin >> vertexCount >> edgeCount >> queryCount;

    if (!vertexCount)
        return 0;

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));
    vector<vector<int>> feast(vertexCount, vector<int>(vertexCount));

    for (int v = 0; v < vertexCount; v++) {
        dist[v][v] = 0;
        cin >> feast[v][v];
    }

    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        if (w < dist[a][b]) {
            dist[a][b] = dist[b][a] = w;
            feast[a][b] = feast[b][a] = max(feast[a][a], feast[b][b]);
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int v = 0; v < vertexCount; v++) {
            for (int a = 0; a < vertexCount; a++) {
                for (int b = 0; b < vertexCount; b++) {
                    if (dist[a][b] + feast[a][b] > dist[a][v] + dist[v][b] + max(feast[a][v], feast[v][b])) {
                        dist[a][b] = dist[a][v] + dist[v][b];
                        feast[a][b] = max(feast[a][v], feast[v][b]);
                    }
                }
            }
        }
    }

    if (test > 1)
        cout << "\n";
    cout << "Case #" << test << "\n";

    for (int i = 0; i < queryCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (dist[a][b] != 1e9)
            cout << dist[a][b] + feast[a][b] << "\n";
        else
            cout << "-1\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}