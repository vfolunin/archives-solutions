#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Edge {
    int a, ta, b, tb;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, start, finish, edgeCount;
    cin >> vertexCount >> start >> finish >> edgeCount;
    start--;
    finish--;

    vector<Edge> edges(edgeCount);
    for (auto &[a, ta, b, tb] : edges) {
        cin >> a >> ta >> b >> tb;
        a--;
        b--;
    }

    vector<int> dist(vertexCount, 1e9);
    dist[start] = 0;

    for (int i = 0; i < edgeCount; i++)
        for (auto &[a, ta, b, tb] : edges)
            if (dist[a] <= ta && dist[b] > tb)
                dist[b] = tb;

    cout << dist[finish];
}