#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

void bfs(vector<vector<int>> &graph, int start, int finish) {
    vector<int> dist(graph.size(), 1e9);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == finish) {
            cout << max(0, dist[v] / 2 - 1);
            return;
        }

        for (int to : graph[v]) {
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    cout << "Call a taxi!";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int stopCount, busCount;
    cin >> stopCount >> busCount;

    vector<vector<int>> graph(stopCount + busCount);
    for (int bus = 0; bus < busCount; bus++) {
        int stops;
        cin >> stops;

        for (int i = 0; i < stops; i++) {
            int stop;
            cin >> stop;
            stop--;

            graph[stop].push_back(stopCount + bus);
            graph[stopCount + bus].push_back(stop);
        }
    }

    int start, finish;
    cin >> start >> finish;
    start--;
    finish--;

    bfs(graph, start, finish);
}