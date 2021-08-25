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
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (!vertexCount && !edgeCount)
        return 0;

    vector<Edge> edges(edgeCount);
    for (auto &[a, b, w] : edges) {
        cin >> a >> b >> w;
        a--;
        b--;
    }

    vector<int> dist(vertexCount, -1e9);
    dist[0] = 0;

    for (int i = 0; i < vertexCount; i++) {
        for (auto &[a, b, w] : edges) {
            if (dist[a] != -1e9 && dist[b] < dist[a] + w) {
                dist[b] = dist[a] + w;
                if (i + 1 == vertexCount) {
                    cout << "Unlimited!\n";
                    return 1;
                }
            }
        }
    }

    cout << *max_element(dist.begin(), dist.end()) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}