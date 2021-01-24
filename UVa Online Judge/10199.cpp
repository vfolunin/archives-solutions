#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<int>> g;
    vector<int> visited;
    vector<int> depth;
    vector<int> upDepth;
    set<int> cutpoints;

    Graph(int vertexCount) {
        g.resize(vertexCount);
        visited.resize(vertexCount);
        depth.resize(vertexCount);
        upDepth.resize(vertexCount);
    }

    void addEdge(int a, int b) {
        g[a].push_back(b);
        g[b].push_back(a);
    }

    void dfs(int v, int p) {
        visited[v] = 1;
        depth[v] = (p == -1 ? 0 : depth[p] + 1);
        upDepth[v] = depth[v];
        int childrenCount = 0;

        for (int to : g[v]) {
            if (to == p) {
                continue;
            } else if (!visited[to]) {
                dfs(to, v);
                childrenCount++;
                upDepth[v] = min(upDepth[v], upDepth[to]);
                if (p != -1 && upDepth[to] >= depth[v])
                    cutpoints.insert(v);
            } else {
                upDepth[v] = min(upDepth[v], depth[to]);
            }
        }

        if (p == -1 && childrenCount > 1) {
            cutpoints.insert(v);
        }
    }

    void findCutpoints() {
        for (int v = 0; v < g.size(); v++)
            if (!visited[v])
                dfs(v, -1);
    }
};

bool solve(int test) {
    int vertexCount;
    cin >> vertexCount;

    if (!vertexCount)
        return 0;

    vector<string> vertexName(vertexCount);
    for (string &name : vertexName)
        cin >> name;
    sort(vertexName.begin(), vertexName.end());

    map<string, int> vertexId;
    for (string &name : vertexName)
        vertexId[name] = vertexId.size();

    int edgeCount;
    cin >> edgeCount;

    Graph graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        string a, b;
        cin >> a >> b;
        graph.addEdge(vertexId[a], vertexId[b]);
    }

    graph.findCutpoints();

    if (test > 1)
        cout << "\n";
    cout << "City map #" << test << ": " << graph.cutpoints.size() << " camera(s) found\n";
    for (int cutpoint : graph.cutpoints)
        cout << vertexName[cutpoint] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}