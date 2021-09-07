#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Edge {
    int a, b, w;
};

bool solve(int test) {
    int vertexCount, edgeCount;
    if (!(cin >> vertexCount >> edgeCount))
        return 0;

    vector<Edge> edges(edgeCount);
    for (auto &[a, b, w] : edges)
        cin >> a >> b >> w;

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));
    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 0;
    for (auto &[a, b, w] : edges)
        dist[a][b] = dist[b][a] = w;

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    vector<vector<int>> res(vertexCount, vector<int>(vertexCount, 1e9));
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            for (auto &[aa, bb, w] : edges) {
                if (dist[a][aa] + w + dist[bb][b] != dist[a][b])
                    res[a][b] = min(res[a][b], dist[a][aa] + w + dist[bb][b]);
                if (dist[a][bb] + w + dist[aa][b] != dist[a][b])
                    res[a][b] = min(res[a][b], dist[a][bb] + w + dist[aa][b]);
            }
        }
    }

    int queryCount;
    cin >> queryCount;

    cout << "Set #" << test << "\n";
    for (int i = 0; i < queryCount; i++) {
        int a, b;
        cin >> a >> b;
        if (res[a][b] == 1e9)
            cout << "?\n";
        else
            cout << res[a][b] << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}