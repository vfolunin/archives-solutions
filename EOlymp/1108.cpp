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

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<Edge> edges(edgeCount);
    for (auto &[a, b, w] : edges)
        cin >> a >> b >> w;

    vector<long long> dist(vertexCount, 1e18);
    dist[0] = 0;

    for (int i = 0; i < vertexCount; i++) {
        for (auto &[a, b, w] : edges) {
            if (dist[a] != 1e18 && dist[b] > dist[a] + w) {
                if (i == vertexCount - 1) {
                    cout << "possible";
                    return 0;
                }
                dist[b] = dist[a] + w;
            }
        }
    }

    cout << "not possible";
}