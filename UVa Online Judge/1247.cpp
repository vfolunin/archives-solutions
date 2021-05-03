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

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    const int INF = 1e9;
    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, INF));
    vector<vector<int>> edges(vertexCount, vector<int>(vertexCount, INF));
    vector<vector<int>> pred(vertexCount, vector<int>(vertexCount, -1));
    for (int v = 0; v < vertexCount; v++) {
        dist[v][v] = 0;
        edges[v][v] = 0;
    }

    for (int i = 0; i < edgeCount; i++) {
        char a, b;
        int w;
        cin >> a >> b >> w;
        a -= 'A';
        b -= 'A';

        dist[a][b] = dist[b][a] = w;
        edges[a][b] = edges[b][a] = 1;
        pred[a][b] = a;
        pred[b][a] = b;
    }

    
    for (int v = 0; v < vertexCount; v++) {
        for (int a = 0; a < vertexCount; a++) {
            for (int b = 0; b < vertexCount; b++) {
                if (dist[a][b] > dist[a][v] + dist[v][b] ||
                    dist[a][b] == dist[a][v] + dist[v][b] && edges[a][b] > edges[a][v] + edges[v][b]) {
                    dist[a][b] = dist[a][v] + dist[v][b];
                    edges[a][b] = edges[a][v] + edges[v][b];
                    pred[a][b] = (v != b ? pred[v][b] : pred[a][v]);
                }
            }
        }
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        char a, b;
        cin >> a >> b;
        a -= 'A';
        b -= 'A';

        vector<int> path = { b };
        for (int v = pred[a][b]; v != -1; v = pred[a][v])
            path.push_back(v);
        reverse(path.begin(), path.end());

        for (int i = 0; i < path.size(); i++)
            cout << (char)(path[i] + 'A') << (i + 1 < path.size() ? " " : "\n");
    }
}