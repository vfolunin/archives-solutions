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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount));
    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            cin >> dist[a][b];

    for (int v = 0; v < vertexCount; v++) {
        for (int a = 0; a < vertexCount; a++) {
            for (int b = a + 1; b < vertexCount; b++) {
                if (dist[a][b] > dist[a][v] + dist[v][b]) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    long long res = 0;
    for (int a = 0; a < vertexCount; a++) {
        for (int b = a + 1; b < vertexCount; b++) {
            bool critical = 1;
            for (int v = 0; critical && v < vertexCount; v++)
                if (v != a && v != b && dist[a][b] == dist[a][v] + dist[v][b])
                    critical = 0;

            if (critical)
                res += dist[a][b];
        }
    }

    cout << res;
}