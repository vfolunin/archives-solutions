#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

class Graph {
    struct Edge {
        int a, b, capacity, flow;

        Edge(int a, int b, int capacity) :
            a(a), b(b), capacity(capacity), flow(0) {}

        int other(int v) const {
            return v == a ? b : a;
        }

        int capacityTo(int v) const {
            return v == b ? capacity - flow : flow;
        }

        void addFlowTo(int v, int f) {
            flow += (v == b ? f : -f);
        }
    };

    vector<Edge> edges;
    vector<vector<int>> g;
    vector<bool> visited;
    vector<int> edgeTo;

    void bfs(int v) {
        queue<int> q;
        visited[v] = 1;
        q.push(v);
        while (!q.empty()) {
            v = q.front();
            q.pop();
            for (int e : g[v]) {
                int to = edges[e].other(v);
                if (!visited[to] && edges[e].capacityTo(to)) {
                    edgeTo[to] = e;
                    visited[to] = 1;
                    q.push(to);
                }
            }
        }
    }

    bool hasPath(int from, int to) {
        fill(visited.begin(), visited.end(), 0);
        bfs(from);
        return visited[to];
    }

    int bottleneckCapacity(int from, int to) {
        int bCapacity = 1e9;
        for (int v = to; v != from; v = edges[edgeTo[v]].other(v))
            bCapacity = min(bCapacity, edges[edgeTo[v]].capacityTo(v));
        return bCapacity;
    }

    void addFlow(int from, int to, int flow) {
        for (int v = to; v != from; v = edges[edgeTo[v]].other(v))
            edges[edgeTo[v]].addFlowTo(v, flow);
    }

    void dfs(int v) {
        visited[v] = 1;
        for (int e : g[v]) {
            int to = edges[e].other(v);
            if (!visited[to] && edges[e].flow) {
                edgeTo[to] = e;
                dfs(to);
            }
        }
    }

public:
    Graph(int vertexCount) {
        g.resize(vertexCount);
        visited.resize(vertexCount);
        edgeTo.resize(vertexCount);
    }

    void addEdge(int from, int to, int capacity) {
        edges.push_back(Edge(from, to, capacity));
        g[from].push_back(edges.size() - 1);
        g[to].push_back(edges.size() - 1);
    }

    long long maxFlow(int from, int to) {
        long long flow = 0;
        while (hasPath(from, to)) {
            int deltaFlow = bottleneckCapacity(from, to);
            addFlow(from, to, deltaFlow);
            flow += deltaFlow;
        }
        return flow;
    }

    vector<int> getPath(int from, int to) {
        visited.assign(g.size(), 0);
        edgeTo.assign(g.size(), -1);
        dfs(from);

        vector<int> path;
        for (int v = to; v != from; v = edges[edgeTo[v]].other(v)) {
            path.push_back(v);
            edges[edgeTo[v]].flow = 0;
        }
        path.push_back(from);
        reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    Graph graph(vertexCount);

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1, 1);
    }

    int pathCount = graph.maxFlow(0, vertexCount - 1);

    cout << pathCount << "\n";
    for (int i = 0; i < pathCount; i++) {
        vector<int> path = graph.getPath(0, vertexCount - 1);
        cout << path.size() << "\n";
        for (int v : path)
            cout << v + 1 << " ";
        cout << "\n";
    }
}