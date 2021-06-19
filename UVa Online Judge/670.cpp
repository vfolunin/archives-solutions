#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    double x, y;

    double distTo(const Point &that) const {
        return hypot(x - that.x, y - that.y);
    }
};

struct Graph {
    struct Edge {
        int a, b, capacity, flow;
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


void solve(int test) {
    int aSize, bSize;
    cin >> aSize >> bSize;

    vector<Point> a(aSize), b(bSize);
    for (auto &[x, y] : a)
        cin >> x >> y;
    for (auto &[x, y] : b)
        cin >> x >> y;

    Graph graph(aSize + bSize + 1);

    for (int i = 1; i < aSize; i++)
        graph.addEdge(0, i, 1);

    for (int i = 1; i < aSize; i++)
        for (int j = 0; j < bSize; j++)
            if (a[i - 1].distTo(a[i]) * 2 >= a[i - 1].distTo(b[j]) + b[j].distTo(a[i]) - 1e-9)
                graph.addEdge(i, aSize + j, 1);

    for (int i = 0; i < bSize; i++)
        graph.addEdge(aSize + i, aSize + bSize, 1);

    graph.maxFlow(0, aSize + bSize);

    vector<int> next(aSize + bSize);
    for (int i = 0; i < aSize; i++)
        next[i] = i + 1;

    for (auto &[a, b, _, f] : graph.edges) {
        if (1 <= a && b < aSize + bSize && f) {
            next[a - 1] = b;
            next[b] = a;
        }
    }

    vector<pair<int, int>> path;
    for (int i = 0; 1; i = next[i]) {
        pair<int, int> p;
        if (i < aSize)
            p = { a[i].x, a[i].y };
        else
            p = { b[i - aSize].x, b[i - aSize].y };
        path.push_back(p);
        if (i == aSize - 1)
            break;
    }

    if (test)
        cout << "\n";
    cout << path.size() << "\n";
    for (int i = 0; i < path.size(); i++)
        cout << path[i].first << " " << path[i].second << (i + 1 < path.size() ? " " : "\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}