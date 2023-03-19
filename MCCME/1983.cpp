#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<pair<int, int>>> &graph, int v, vector<int> &dist) {
    for (auto &[to, w] : graph[v]) {
        if (dist[to] == 1e9) {
            dist[to] = dist[v] + w;
            dfs(graph, to, dist);
        }
    }
}

pair<double, vector<int>> dijkstra(vector<vector<pair<int, int>>> &graph, vector<vector<double>> &time) {
    vector<int> visited(graph.size());
    vector<double> minTime(graph.size(), 1e9);
    minTime[0] = 0;
    vector<int> from(graph.size(), -1);

    for (int i = 0; i < graph.size(); i++) {
        int v = -1;
        for (int j = 0; j < graph.size(); j++)
            if (!visited[j] && (v == -1 || minTime[v] > minTime[j]))
                v = j;

        visited[v] = 1;

        for (int to = 0; to < graph.size(); to++) {
            if (minTime[to] > minTime[v] + time[v][to]) {
                minTime[to] = minTime[v] + time[v][to];
                from[to] = v;
            }
        }
    }

    int finish = max_element(minTime.begin(), minTime.end()) - minTime.begin();
    vector<int> path;
    for (int v = finish; v != -1; v = from[v])
        path.push_back(v);

    return { minTime[finish], path };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<double> wait(vertexCount), speed(vertexCount);
    for (int v = 0; v < vertexCount; v++)
        cin >> wait[v] >> speed[v];

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < vertexCount - 1; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        graph[a].push_back({ b, w });
        graph[b].push_back({ a, w });
    }

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));
    for (int v = 0; v < vertexCount; v++) {
        dist[v][v] = 0;
        dfs(graph, v, dist[v]);
    }

    vector<vector<double>> time(vertexCount, vector<double>(vertexCount));
    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            time[a][b] = wait[b] + dist[a][b] / speed[b];

    auto [finishTime, path] = dijkstra(graph, time);

    cout << fixed << finishTime << "\n";
    for (int v : path)
        cout << v + 1 << " ";
}