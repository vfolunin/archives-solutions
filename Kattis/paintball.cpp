#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
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
            if (!visited[to] && edges[e].capacityTo(to))
                dfs(to);
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
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    Graph graph(1 + vertexCount + vertexCount + 1);

    for (int a = 0; a < vertexCount; a++)
        graph.addEdge(0, 1 + a, 1);

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;

        graph.addEdge(a, vertexCount + b, 1);
        graph.addEdge(b, vertexCount + a, 1);
    }

    for (int b = 0; b < vertexCount; b++)
        graph.addEdge(1 + vertexCount + b, 1 + vertexCount + vertexCount, 1);

    if (graph.maxFlow(0, 1 + vertexCount + vertexCount) < vertexCount) {
        cout << "Impossible";
        return 0;
    }

    vector<int> res(vertexCount);
    for (auto &[a, b, c, f] : graph.edges)
        if (f && a && b != 1 + vertexCount + vertexCount)
            res[a - 1] = b - 1 - vertexCount;

    for (int v : res)
        cout << v + 1 << "\n";
}