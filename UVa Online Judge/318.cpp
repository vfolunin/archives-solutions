#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int start) {
    vector<int> dist(graph.size(), 1e9);
    set<pair<int, int>> q;

    dist[start] = 0;
    q.insert({ dist[start], start });

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto &[to, w] : graph[v]) {
            if (dist[to] > dist[v] + w) {
                q.erase({ dist[to], to });
                dist[to] = dist[v] + w;
                q.insert({ dist[to], to });
            }
        }
    }

    return dist;
}

bool solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    if (!vertexCount)
        return 0;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        graph[a].push_back({ b, w });
        graph[b].push_back({ a, w });
    }

    vector<int> dist = dijkstra(graph, 0);

    int v1 = max_element(dist.begin(), dist.end()) - dist.begin();
    double t1 = dist[v1];

    int a2, b2;
    double t2 = 0;
    for (int a = 0; a < vertexCount; a++) {
        for (auto &[b, w] : graph[a]) {
            double t = (dist[a] + dist[b] + w) / 2.0;
            if (t2 < t) {
                a2 = a;
                b2 = b;
                t2 = t;
            }
        }
    }

    cout << "System #" << test << "\n";
    cout.precision(1);
    if (t1 >= t2) {
        cout << "The last domino falls after " << fixed << t1 << " seconds,";
        cout << " at key domino " << v1 + 1 << ".\n\n";
    } else {
        cout << "The last domino falls after " << fixed << t2 << " seconds,";
        cout << " between key dominoes " << a2 + 1 << " and " << b2 + 1 << ".\n\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}