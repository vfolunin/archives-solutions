#include <iostream>
#include <algorithm>
#include <cmath>
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
    int gopherCount, holeCount;
    double time, velocity;
    if (!(cin >> gopherCount >> holeCount >> time >> velocity))
        return 0;

    vector<pair<double, double>> gopherPos(gopherCount);
    for (auto &[x, y] : gopherPos)
        cin >> x >> y;

    vector<pair<double, double>> holePos(holeCount);
    for (auto &[x, y] : holePos)
        cin >> x >> y;

    Graph graph(1 + gopherCount + holeCount + 1);

    for (int i = 0; i < gopherCount; i++)
        graph.addEdge(0, 1 + i, 1);

    for (int i = 0; i < gopherCount; i++) {
        for (int j = 0; j < holeCount; j++) {
            double dx = gopherPos[i].first - holePos[j].first;
            double dy = gopherPos[i].second - holePos[j].second;
            if (time * velocity >= hypot(dx, dy) - 1e-9)
                graph.addEdge(1 + i, 1 + gopherCount + j, 1);
        }
    }

    for (int i = 0; i < holeCount; i++)
        graph.addEdge(1 + gopherCount + i, 1 + gopherCount + holeCount, 1);

    cout << gopherCount - graph.maxFlow(0, 1 + gopherCount + holeCount) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}