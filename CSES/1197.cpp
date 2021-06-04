#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    struct Edge {
        int a, b, w;
    };

    int vertexCount;
    vector<Edge> edges;
    vector<int> pred;

    Graph(int vertexCount) : vertexCount(vertexCount), pred(vertexCount, -1) {}

    void addEdge(int a, int b, int w) {
        edges.push_back({ a, b, w });
    }

    vector<int> fordBellman() {
        vector<long long> dist(vertexCount, 1LL << 60);
        dist[0] = 0;

        for (int i = 0; i < vertexCount; i++) {
            for (auto &[a, b, w] : edges) {
                if (dist[b] > dist[a] + w) {
                    dist[b] = dist[a] + w;
                    pred[b] = a;

                    if (i == vertexCount - 1) {
                        for (int i = 0; i < vertexCount; i++)
                            b = pred[b];

                        vector<int> cycle = { b };
                        for (int v = pred[b]; v != b; v = pred[v])
                            cycle.push_back(v);
                        cycle.push_back(b);

                        reverse(cycle.begin(), cycle.end());
                        return cycle;
                    }
                }
            }
        }

        return {};
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    Graph graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph.addEdge(a - 1, b - 1, w);
    }

    auto cycle = graph.fordBellman();
    if (!cycle.empty()) {
        cout << "YES\n";
        for (int v : cycle)
            cout << v + 1 << " ";
    } else {
        cout << "NO";
    }
}