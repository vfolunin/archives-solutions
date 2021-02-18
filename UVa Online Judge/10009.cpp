#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<string> vertexName;
    map<string, int> vertexId;
    vector<vector<int>> g;

    Graph(int vertexCount) {
        g.resize(vertexCount);
    }

    int getId(string &name) {
        if (!vertexId.count(name)) {
            vertexId[name] = vertexId.size();
            vertexName.push_back(name);
        }
        return vertexId[name];
    }

    void addEdge(string &a, string &b) {
        g[getId(a)].push_back(getId(b));
        g[getId(b)].push_back(getId(a));
    }

    string bfs(string &a, string &b) {
        vector<string> dist(g.size());
        dist[getId(a)] = a[0];
        queue<int> q;
        q.push(getId(a));

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int to : g[v]) {
                if (dist[to].empty()) {
                    dist[to] = dist[v] + vertexName[to][0];
                    q.push(to);
                }
            }
        }

        return dist[getId(b)];
    }
};

void solve(int test) {
    int vertexCount, queryCount;
    cin >> vertexCount >> queryCount;
    vertexCount++;

    Graph graph(vertexCount);

    for (int i = 0; i < vertexCount - 1; i++) {
        string a, b;
        cin >> a >> b;
        graph.addEdge(a, b);
    }

    if (test)
        cout << "\n";
    for (int i = 0; i < queryCount; i++) {
        string a, b;
        cin >> a >> b;
        cout << graph.bfs(a, b) << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}