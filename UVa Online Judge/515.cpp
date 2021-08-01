#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int vertexCount, edgeCount;
    if (!(cin >> vertexCount >> edgeCount))
        return 0;
    vertexCount++;

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));
    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 0;

    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        string op;
        cin >> a >> b >> op >> w;

        b += a;
        a--;
        if (op == "lt")
            dist[b][a] = min(dist[b][a], w - 1);
        else
            dist[a][b] = min(dist[a][b], -w - 1);
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                if (dist[a][v] != 1e9 && dist[v][b] != 1e9 && dist[a][b] > dist[a][v] + dist[v][b])
                    dist[a][b] = max<int>(dist[a][v] + dist[v][b], -1e9);

    for (int v = 0; v < vertexCount; v++) {
        if (dist[v][v] < 0) {
            cout << "successful conspiracy\n";
            return 1;
        }
    }
    
    cout << "lamentable kingdom\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}