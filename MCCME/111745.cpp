#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Edge {
    int a, b, w;

    int other(int v) {
        return v == a ? b : a;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  
    int vertexCount, edgeCount, stopCount;
    cin >> vertexCount >> edgeCount >> stopCount;

    vector<Edge> edges(edgeCount);
    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, -1e9));
    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 0;
    vector<vector<int>> next(vertexCount, vector<int>(vertexCount, -1));

    for (int i = 0; i < edgeCount; i++) {
        auto &[a, b, w] = edges[i];
        cin >> a >> b >> w;
        a--;
        b--;
        dist[a][b] = w;
        next[a][b] = i;
    }

    for (int v = 0; v < vertexCount; v++) {
        for (int a = 0; a < vertexCount; a++) {
            for (int b = 0; b < vertexCount; b++) {
                if (dist[a][v] != -1e9 && dist[v][b] != -1e9 && dist[a][b] < dist[a][v] + dist[v][b]) {
                    dist[a][b] = dist[a][v] + dist[v][b];
                    next[a][b] = next[a][v];
                }
            }
        }
    }

    vector<int> stops(stopCount);
    for (int &v : stops) {
        cin >> v;
        v--;
    }

    vector<int> path;
    for (int stopIndex = 0; stopIndex + 1 < stopCount; stopIndex++) {
        int start = stops[stopIndex];
        int finish = stops[stopIndex + 1];

        for (int v = 0; v < vertexCount; v++) {
            if (dist[start][v] != -1e9 && dist[v][finish] != -1e9 && dist[v][v] > 0) {
                cout << "infinitely kind";
                return 0;
            }
        }

        for (int v = start; v != finish; v = edges[next[v][finish]].other(v))
            path.push_back(next[v][finish]);
    }

    cout << path.size() << "\n";
    for (int e : path)
        cout << e + 1 << " ";
}