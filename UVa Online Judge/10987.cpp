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

void solve(int test) {
    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount));
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < a; b++) {
            cin >> dist[a][b];
            dist[b][a] = dist[a][b];
        }
    }

    cout << "Case #" << test << ":\n";

    for (int v = 0; v < vertexCount; v++) {
        for (int a = 0; a < vertexCount; a++) {
            for (int b = a + 1; b < vertexCount; b++) {
                if (dist[a][b] > dist[a][v] + dist[v][b]) {
                    cout << "Need better measurements.\n\n";
                    return;
                }
            }
        }
    }

    vector<Edge> edges;

    for (int a = 0; a < vertexCount; a++) {
        for (int b = a + 1; b < vertexCount; b++) {
            bool critical = 1;
            for (int v = 0; critical && v < vertexCount; v++)
                if (v != a && v != b && dist[a][b] == dist[a][v] + dist[v][b])
                    critical = 0;

            if (critical)
                edges.push_back({ a, b, dist[a][b] });
        }
    }

    cout << edges.size() << "\n";
    for (auto &[a, b, w] : edges)
        cout << a + 1 << " " << b + 1 << " " << w << "\n";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}