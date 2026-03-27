#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

class Graph {
    class Edge {
        int a, b, capacity, flow;
    public:
        Edge(int a, int b, int capacity) : a(a), b(b), capacity(capacity), flow(0) {}
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
    vector<bool> used;
    vector<int> edgeTo;
    void bfs(int v) {
        queue<int> q;
        used[v] = 1;
        q.push(v);
        while (!q.empty()) {
            v = q.front();
            q.pop();
            for (int e : g[v]) {
                int to = edges[e].other(v);
                if (!used[to] && edges[e].capacityTo(to)) {
                    edgeTo[to] = e;
                    used[to] = 1;
                    q.push(to);
                }
            }
        }
    }
    bool hasPath(int from, int to) {
        fill(used.begin(), used.end(), 0);
        bfs(from);
        return used[to];
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
public:
    Graph(int verticesCount) {
        g.resize(verticesCount);
        used.resize(verticesCount);
        edgeTo.resize(verticesCount);
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
};

void solve() {
    int n;
    double maxDist;
    cin >> n >> maxDist;

    vector<double> x(n), y(n);
    vector<int> penguinCount(n), limit(n);
    int totalPenguinCount = 0;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> penguinCount[i] >> limit[i];
        totalPenguinCount += penguinCount[i];
    }

    vector<vector<int>> can(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            can[i][j] = (i != j && hypot(x[i] - x[j], y[i] - y[j]) <= maxDist + 1e-9);

    Graph graph(1 + n + n);

    for (int i = 0; i < n; i++) {
        graph.addEdge(0, 1 + i, penguinCount[i]);
        graph.addEdge(1 + i, 1 + n + i, limit[i]);

        for (int j = 0; j < n; j++)
            if (can[i][j])
                graph.addEdge(1 + n + i, 1 + j, 1e9);
    }

    vector<int> sinks;
    for (int i = 0; i < n; i++) {
        Graph g = graph;
        if (g.maxFlow(0, 1 + i) == totalPenguinCount)
            sinks.push_back(i);
    }

    if (sinks.empty()) {
        cout << "-1\n";
    } else {
        for (int i = 0; i < sinks.size(); i++)
            cout << sinks[i] << (i + 1 < sinks.size() ? " " : "\n");
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}