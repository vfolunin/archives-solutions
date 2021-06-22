#include <iostream>
#include <algorithm>
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
    int h, w, bankCount;
    cin >> h >> w >> bankCount;

    Graph graph(1 + h * w + h * w + 1);

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            graph.addEdge(1 + y * w + x, 1 + h * w + y * w + x, 1);
            if (y) {
                graph.addEdge(1 + h * w + (y - 1) * w + x, 1 + y * w + x, 1);
                graph.addEdge(1 + h * w + y * w + x, 1 + (y - 1) * w + x, 1);
            }
            if (x) {
                graph.addEdge(1 + h * w + y * w + x - 1, 1 + y * w + x, 1);
                graph.addEdge(1 + h * w + y * w + x, 1 + y * w + x - 1, 1);
            }
            if (y == 0 || y == h - 1 || x == 0 || x == w - 1)
                graph.addEdge(1 + h * w + y * w + x, 1 + h * w + h * w, 1);
        }
    }

    for (int i = 0; i < bankCount; i++) {
        int y, x;
        cin >> y >> x;
        y--;
        x--;
        graph.addEdge(0, 1 + y * w + x, 1);
    }

    cout << (graph.maxFlow(0, 1 + h * w + h * w) == bankCount ? "possible\n" : "not possible\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}