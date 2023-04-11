#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    vector<vector<int>> graph, pos;
    vector<int> l, r, depth, tour;
    int timer;

    Graph(int vertexCount) : graph(vertexCount), l(vertexCount, -1), r(vertexCount), depth(vertexCount) {}

    void addEdge(int a, int b) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    void dfs(int v, int d) {
        l[v] = timer++;
        depth[v] = d;
        tour.push_back(d);
        for (int to : graph[v])
            if (l[to] == -1)
                dfs(to, d + 1);
        r[v] = timer;
    }

    void prepare(int root) {
        timer = 0;
        dfs(root, 0);
        pos.resize(*max_element(tour.begin(), tour.end()) + 1);
        for (int i = 0; i < tour.size(); i++)
            pos[tour[i]].push_back(i);
    }

    int descendantCount(int v, int dist) {
        dist += depth[v];
        if (dist >= pos.size())
            return 0;
        auto q = upper_bound(pos[dist].begin(), pos[dist].end(), r[v]);
        auto p = lower_bound(pos[dist].begin(), pos[dist].end(), l[v]);
        return q - p;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    Graph graph(vertexCount);
    int root = -1;

    for (int v = 0; v < vertexCount; v++) {
        int from;
        cin >> from;

        if (from != -1)
            graph.addEdge(from - 1, v);
        else
            root = v;
    }

    graph.prepare(root);

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int v, dist;
        cin >> v >> dist;

        cout << graph.descendantCount(v - 1, dist) << "\n";
    }
}