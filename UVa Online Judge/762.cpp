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

    int getId(string &name) {
        if (!vertexId.count(name)) {
            vertexId[name] = vertexId.size();
            vertexName.push_back(name);
            g.emplace_back();
        }
        return vertexId[name];
    }

    void addEdge(string &a, string &b) {
        int ai = getId(a);
        int bi = getId(b);
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }

    vector<string> bfs(string &a, string &b) {
        if (!vertexId.count(a) || !vertexId.count(b))
            return {};

        vector<int> prev(g.size(), -2);
        prev[getId(a)] = -1;
        queue<int> q;
        q.push(getId(a));

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int to : g[v]) {
                if (prev[to] == -2) {
                    prev[to] = v;
                    q.push(to);
                }
            }
        }

        vector<string> path;
        for (int v = getId(b); v >= 0; v = prev[v])
            path.push_back(vertexName[v]);
        reverse(path.begin(), path.end());
        return path;
    }
};

bool solve(int test) {
    int edgeCount;
    if (!(cin >> edgeCount))
        return 0;

    Graph graph;

    for (int i = 0; i < edgeCount; i++) {
        string a, b;
        cin >> a >> b;
        graph.addEdge(a, b);
    }

    string a, b;
    cin >> a >> b;
    vector<string> path = graph.bfs(a, b);

    if (test)
        cout << "\n";
    if (path.size() < 2) {
        cout << "No route\n";
    } else {
        for (int i = 1; i < path.size(); i++)
            cout << path[i - 1] << " " << path[i] << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}