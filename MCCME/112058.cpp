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
    vector<vector<int>> next(vertexCount, vector<int>(vertexCount));
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            cin >> dist[a][b];
            next[a][b] = b;
        }
    }

    for (int v = 0; v < vertexCount; v++) {
        for (int a = 0; a < vertexCount; a++) {
            for (int b = 0; b < vertexCount; b++) {
                if (dist[a][v] != -1e9 && dist[v][b] != -1e9 && dist[a][b] > dist[a][v] + dist[v][b]) {
                    dist[a][b] = max<int>(dist[a][v] + dist[v][b], -1e9);
                    next[a][b] = next[a][v];
                }
            }
        }
    }

    for (int v = 0; v < vertexCount; v++) {
        if (dist[v][v] < 0) {
            cout << "No path";
            return 0;
        }
    }

    int resDist = 1e9, resA, resB;
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            if (a != b && resDist > dist[a][b]) {
                resDist = dist[a][b];
                resA = a;
                resB = b;
            }
        }
    }

    vector<int> path;
    for (; resA != resB; resA = next[resA][resB])
        path.push_back(resA);
    path.push_back(resB);

    cout << resDist << " " << path.size() << "\n";
    for (int v : path)
        cout << v + 1 << " ";
}