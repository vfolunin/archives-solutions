#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

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

class Graph {
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

bool solve() {
    int vertexCount;
    if (!(cin >> vertexCount))
        return 0;

    Graph graph(1 + vertexCount + vertexCount + 1);

    for (int i = 0; i < vertexCount; i++) {
        int cap;
        cin >> cap;
        graph.addEdge(1 + i, 1 + vertexCount + i, cap);
    }

    int edgeCount;
    cin >> edgeCount;

    for (int i = 0; i < edgeCount; i++) {
        int a, b, cap;
        cin >> a >> b >> cap;
        a--;
        b--;
        graph.addEdge(1 + vertexCount + a, 1 + b, cap);
    }

    int sourceCount, sinkCount;
    cin >> sourceCount >> sinkCount;

    for (int i = 0; i < sourceCount; i++) {
        int v;
        cin >> v;
        v--;
        graph.addEdge(0, 1 + v, 1e9);
    }

    for (int i = 0; i < sinkCount; i++) {
        int v;
        cin >> v;
        v--;
        graph.addEdge(1 + vertexCount + v, 1 + vertexCount + vertexCount, 1e9);
    }

    int res = graph.maxFlow(0, 1 + vertexCount + vertexCount);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}