#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> readInts() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> res;
    int x;
    while (ss >> x)
        res.push_back(x);
    return res;
}

pair<int, vector<int>> dijkstra(vector<vector<pair<int, int>>> &graph, int start, int finish) {
    vector<int> dist(graph.size(), 1e9);
    vector<int> pred(graph.size(), -1);
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
                pred[to] = v;
                q.insert({ dist[to], to });
            }
        }
    }

    vector<int> path;
    for (int v = finish; v != -1; v = pred[v])
        path.push_back(v);
    reverse(path.begin(), path.end());

    return { dist[finish], path };
}

void solve(int test) {
    vector<vector<int>> edgeWeight(1);
    edgeWeight[0] = readInts();

    int vertexCount = edgeWeight[0].size();
    edgeWeight.resize(vertexCount);
    for (int i = 1; i < edgeWeight.size(); i++)
        edgeWeight[i] = readInts();

    vector<int> vertexWeight = readInts();

    vector<vector<pair<int, int>>> graph(vertexCount * 2);

    for (int a = 0; a < vertexCount; a++)
        for (int b = 0; b < vertexCount; b++)
            if (edgeWeight[a][b] != -1)
                graph[vertexCount + a].push_back({ b, edgeWeight[a][b] });

    for (int v = 0; v < vertexCount; v++)
        graph[v].push_back({ vertexCount + v, vertexWeight[v] });

    if (test)
        cout << "\n";

    for (int i = 0; 1; i++) {
        vector<int> query = readInts();
        if (query.empty())
            break;

        auto [cost, path] = dijkstra(graph, vertexCount + query[0] - 1, query[1] - 1);

        if (i)
            cout << "\n";
        cout << "From " << query[0] << " to " << query[1] << " :\n";
        cout << "Path: " << query[0];
        if (query[0] != query[1])
            for (int i = 1; i < path.size(); i += 2)
                cout << "-->" << path[i] + 1;
        cout << "\nTotal cost : " << cost << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore(2);

    for (int i = 0; i < n; i++)
        solve(i);
}