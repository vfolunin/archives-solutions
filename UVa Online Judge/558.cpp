#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const int INF = 1e9;

struct Edge {
    int a, b, w;
};

void solve() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<Edge> edges(edgeCount);
    for (Edge &e : edges)
        cin >> e.a >> e.b >> e.w;

    vector<int> dist(vertexCount, INF);
    dist[0] = 0;

    for (int i = 0; i < vertexCount; i++)
        for (auto &[a, b, w] : edges)
            dist[b] = min(dist[b], dist[a] + w);
    
    for (auto &[a, b, w] : edges) {
        if (dist[b] > dist[a] + w) {
            cout << "possible\n";
            return;
        }
    }

    cout << "not possible\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}