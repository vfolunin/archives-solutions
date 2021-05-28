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

bool can(vector<vector<double>> &dist, int limit, int matchingSize) {
    Graph graph(1 + dist.size() + dist[0].size() + 1);

    for (int a = 0; a < dist.size(); a++)
        graph.addEdge(0, 1 + a, 1);

    for (int a = 0; a < dist.size(); a++)
        for (int b = 0; b < dist[0].size(); b++)
            if (dist[a][b] <= limit)
                graph.addEdge(1 + a, 1 + dist.size() + b, 1);

    for (int b = 0; b < dist[0].size(); b++)
        graph.addEdge(1 + dist.size() + b, 1 + dist.size() + dist[0].size(), 1);

    return graph.maxFlow(0, 1 + dist.size() + dist[0].size()) >= matchingSize;
}

void solve() {
    int pointCount, matchingSize;
    cin >> pointCount >> matchingSize;

    vector<int> ax, ay, bx, by;
    for (int i = 0; i < pointCount; i++) {
        int x, y;
        string color;
        cin >> x >> y >> color;

        if (color == "red") {
            ax.push_back(x);
            ay.push_back(y);
        } else {
            bx.push_back(x);
            by.push_back(y);
        }
    }

    if (ax.empty() || ay.empty()) {
        cout << "Impossible\n";
        return;
    }

    vector<vector<double>> dist(ax.size(), vector<double>(bx.size(), -1));
    for (int a = 0; a < ax.size(); a++)
        for (int b = 0; b < bx.size(); b++)
            dist[a][b] = hypot(ax[a] - bx[b], ay[a] - by[b]);

    int l = 0, r = 5000;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(dist, m, matchingSize))
            r = m;
        else
            l = m;
    }

    if (r == 5000)
        cout << "Impossible\n";
    else
        cout << r << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}