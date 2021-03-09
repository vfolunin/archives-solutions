#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int vertexCount;
    cin >> vertexCount;

    if (!vertexCount)
        return 0;

    vector<vector<pair<int, int>>> graph(vertexCount);

    for (int v = 0; v < vertexCount; v++) {
        int edgeCount;
        cin >> edgeCount;

        graph[v].resize(edgeCount);
        for (auto &[to, w] : graph[v]) {
            cin >> to >> w;
            to--;
        }
    }

    int start, finish;
    cin >> start >> finish;
    start--;
    finish--;

    vector<int> dist(vertexCount, 1e9);
    vector<int> pred(vertexCount, -1);
    set<pair<int, int>> q;

    dist[start] = 0;
    q.insert({ 0, start });

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto &[to, w] : graph[v]) {
            if (dist[to] > dist[v] + w) {
                q.erase({ dist[to], to });
                dist[to] = dist[v] + w;
                pred[to] = v;
                q.insert({ dist[to], to });
            }
        }
    }

    vector<int> path;
    for (int v = finish; v != -1; v = pred[v])
        path.push_back(v);
    reverse(path.begin(), path.end());

    cout << "Case " << test << ": Path =";
    for (int v : path)
        cout << " " << v + 1;
    cout << "; " << dist[finish] << " second delay\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}