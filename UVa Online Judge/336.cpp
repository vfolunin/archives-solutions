#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const int INF = 1 << 20;

bool solve(int &test) {
    int edgeCount;
    cin >> edgeCount;

    if (!edgeCount)
        return 0;

    map<int, int> vertex;
    vector<vector<int>> dist(30, vector<int>(30, INF));
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        int va = vertex.count(a) ? vertex[a] : vertex[a] = vertex.size();
        int vb = vertex.count(b) ? vertex[b] : vertex[b] = vertex.size();
        dist[va][vb] = dist[vb][va] = 1;
    }
    for (int v = 0; v < vertex.size(); v++)
        dist[v][v] = 0;

    for (int v = 0; v < vertex.size(); v++)
        for (int a = 0; a < vertex.size(); a++)
            for (int b = 0; b < vertex.size(); b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    while (1) {
        int start, ttl;
        cin >> start >> ttl;

        if (!start && !ttl)
            break;

        int res = 0;
        if (vertex.count(start)) {
            int v = vertex[start];
            for (int to = 0; to < vertex.size(); to++)
                res += dist[v][to] > ttl;
        } else {
            res = vertex.size();
        }

        cout << "Case " << test++ << ": " << res << " nodes not reachable ";
        cout << "from node " << start << " with TTL = " << ttl << ".\n";
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int test = 1;
    while (solve(test));
}