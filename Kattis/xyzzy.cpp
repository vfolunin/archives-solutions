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

bool solve() {
    int vertexCount;
    cin >> vertexCount;

    if (vertexCount == -1)
        return 0;

    vector<int> value(vertexCount);
    vector<Edge> edges;

    for (int v = 0; v < vertexCount; v++) {
        cin >> value[v];

        int degree;
        cin >> degree;

        for (int i = 0; i < degree; i++) {
            int to;
            cin >> to;
            to--;
            edges.push_back({ v, to, 0 });
        }
    }

    for (auto &[a, b, w] : edges)
        w = value[b];

    vector<int> canReachFinish(vertexCount, 0);
    canReachFinish[vertexCount - 1] = 1;

    for (int i = 0; i < vertexCount; i++)
        for (auto &[a, b, _] : edges)
            canReachFinish[a] |= canReachFinish[b];

    vector<int> dist(vertexCount, -1e9);
    dist[0] = 100;

    for (int i = 0; i < vertexCount; i++) {
        for (auto &[a, b, w] : edges) {
            if (dist[a] != -1e9 && dist[b] < dist[a] + w && dist[a] + w > 0) {
                dist[b] = dist[a] + w;
                if (i == vertexCount - 1 && canReachFinish[b]) {
                    cout << "winnable\n";
                    return 1;
                }
            }
        }
    }

    cout << (dist[vertexCount - 1] > 0 ? "winnable\n" : "hopeless\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}