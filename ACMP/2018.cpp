#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int dijkstra(vector<vector<int>> &graph, int start, int finish) {
    vector<int> dist(graph.size(), 1e9), visited(graph.size());
    dist[start] = 0;

    for (int i = 0; i < graph.size(); i++) {
        int v = -1;
        for (int curV = 0; curV < graph.size(); curV++)
            if (!visited[curV] && (v == -1 || dist[v] > dist[curV]))
                v = curV;

        if (v == finish)
            return dist[v];

        visited[v] = 1;

        for (int to = 0; to < graph.size(); to++)
            if (graph[v][to])
                dist[to] = min(dist[to], dist[v] + graph[v][to]);
    }

    return 1e9;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount, vector<int>(vertexCount));
    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            cin >> graph[a][b];
    
    string s;
    getline(cin, s);
    getline(cin, s);

    vector<string> graph2(vertexCount);
    for (string &s : graph2)
        getline(cin, s);

    vector<int> order(vertexCount);
    iota(order.begin(), order.end(), 0);

    do {
        bool ok = 1;
        for (int v = 0; v < vertexCount && ok; v++) {
            for (char c : graph2[order[v]]) {
                int to = find(order.begin(), order.end(), c - 'A') - order.begin();
                ok &= graph[v][to] != 0;
            }
        }
        if (ok)
            break;
    } while (next_permutation(order.begin(), order.end()));

    char cStart, cFinish;
    cin >> cStart >> cFinish;

    int start = find(order.begin(), order.end(), cStart - 'A') - order.begin();
    int finish = find(order.begin(), order.end(), cFinish - 'A') - order.begin();

    cout << dijkstra(graph, start, finish);
}