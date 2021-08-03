#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    int x, y;
};

struct Rect {
    Point l, r;

    bool has(const Point &p) const {
        return l.x <= p.x && p.x <= r.x && l.y <= p.y && p.y <= r.y;
    }
};

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

bool critical(int slideCount, vector<pair<int, int>> &edges, int edgeI) {
    Graph graph(1 + slideCount + slideCount + 1);

    for (int i = 0; i < slideCount; i++)
        graph.addEdge(0, 1 + i, 1);

    for (int i = 0; i < edges.size(); i++)
        if (i != edgeI)
            graph.addEdge(1 + edges[i].first, 1 + slideCount + edges[i].second, 1);

    for (int i = 0; i < slideCount; i++)
        graph.addEdge(1 + slideCount + i, 1 + slideCount + slideCount, 1);

    return graph.maxFlow(0, 1 + slideCount + slideCount) < slideCount;
}

bool solve(int test) {
    int slideCount;
    cin >> slideCount;

    if (!slideCount)
        return 0;

    vector<Rect> rects(slideCount);
    for (auto &[l, r] : rects)
        cin >> l.x >> r.x >> l.y >> r.y;

    vector<Point> points(slideCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    vector<pair<int, int>> edges;
    for (int i = 0; i < slideCount; i++)
        for (int j = 0; j < slideCount; j++)
            if (rects[i].has(points[j]))
                edges.push_back({ i, j });

    vector<int> res;
    for (int i = 0; i < edges.size(); i++)
        if (critical(slideCount, edges, i))
            res.push_back(i);

    cout << "Heap " << test << "\n";
    if (res.empty()) {
        cout << "none\n\n";
    } else {
        for (int i = 0; i < res.size(); i++) {
            cout << "(" << (char)('A' + edges[res[i]].first);
            cout << "," << 1 + edges[res[i]].second << ")";
            cout << (i + 1 < res.size() ? " " : "\n\n");
        }
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}