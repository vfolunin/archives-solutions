#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Edge {
    int a, b, weight;
};

vector<int> fordBellman(int vertexCount, vector<Edge> &edges) {
    vector<int> dist(vertexCount);
    vector<int> from(vertexCount, -1);

    for (int i = 0; i < vertexCount - 1; i++) {
        for (auto &[a, b, weight] : edges) {
            if (dist[b] > dist[a] + weight) {
                dist[b] = max<int>(dist[a] + weight, -1e9);
                from[b] = a;
            }
        }
    }

    for (auto &[a, b, weight] : edges) {
        if (dist[b] > dist[a] + weight) {
            from[b] = a;

            int v = b;
            for (int i = 0; i < vertexCount - 1; i++)
                v = from[v];

            vector<int> cycle = { v };
            for (int cycleV = from[v]; cycleV != v; cycleV = from[cycleV])
                cycle.push_back(cycleV);
            cycle.push_back(v);
            reverse(cycle.begin(), cycle.end());
            return cycle;
        }
    }

    return {};
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int vertexCount;
    cin >> vertexCount;

    vector<Edge> edges;
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            int weight;
            cin >> weight;

            if (weight != 1e5)
                edges.push_back({ a, b, weight });
        }
    }

    vector<int> cycle = fordBellman(vertexCount, edges);
    if (!cycle.empty()) {
        cout << "YES\n" << cycle.size() << "\n";
        for (int v : cycle)
            cout << v + 1 << " ";
    } else {
        cout << "NO";
    }
}