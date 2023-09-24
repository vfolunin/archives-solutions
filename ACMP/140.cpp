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
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            cin >> dist[a][b];
            if (dist[a][b] == 1e5)
                dist[a][b] = 1e9;
        }
    }

    for (int v = 0; v < vertexCount; v++) {
        for (int a = 0; a < vertexCount; a++) {
            for (int b = 0; b < vertexCount; b++) {
                if (dist[a][v] == 1e9 || dist[v][b] == 1e9)
                    continue;
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);
                dist[a][b] = max<int>(dist[a][b], -1e9);
            }
        }
    }

    for (int v = 0; v < vertexCount; v++) {
        if (dist[v][v] < 0) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}