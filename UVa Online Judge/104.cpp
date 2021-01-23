#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Edge {
    int a, b;
    double w;
};

vector<int> fordBellman(int vertexCount, vector<Edge> &edges, int start) {
    vector<vector<double>> dist(vertexCount + 2, vector<double>(vertexCount));
    vector<vector<int>> pred(vertexCount + 2, vector<int>(vertexCount, -1));
    dist[0][start] = 1;    

    for (int i = 1; i <= vertexCount + 1; i++) {
        for (auto &[a, b, w] : edges) {
            if (dist[i][b] < dist[i - 1][a] * w) {
                dist[i][b] = dist[i - 1][a] * w;
                pred[i][b] = a;
            }
        }

        if (dist[i][start] >= 1.01) {
            vector<int> cycle;
            for (int v = start; i >= 0; v = pred[i][v], i--)
                cycle.push_back(v);
            reverse(cycle.begin(), cycle.end());
            return cycle;
        }
    }

    return {};
}

vector<int> fordBellman(int vertexCount, vector<Edge> &edges) {
    vector<int> minCycle;
    for (int v = 0; v < vertexCount; v++) {
        vector<int> cycle = fordBellman(vertexCount, edges, v);
        if (!cycle.empty() && (minCycle.empty() || cycle.size() < minCycle.size()))
            minCycle.swap(cycle);
    }
    return minCycle;
}

bool solve() {
    int vertexCount;
    if (!(cin >> vertexCount))
        return 0;

    vector<Edge> edges;
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            if (b != a) {
                edges.push_back({ a, b, 0 });
                cin >> edges.back().w;
            }
        }
    }

    vector<int> cycle = fordBellman(vertexCount, edges);
    if (!cycle.empty()) {
        for (int i = 0; i < cycle.size(); i++)
            cout << cycle[i] + 1 << (i + 1 < cycle.size() ? ' ' : '\n');
    } else {
        cout << "no arbitrage sequence exists\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}