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

bool can(vector<vector<double>> &dist, double limit, int maxLoss) {
    Graph graph(1 + dist.size() + dist[0].size() + 1);

    for (int a = 0; a < dist.size(); a++)
        graph.addEdge(0, 1 + a, 1);

    for (int a = 0; a < dist.size(); a++)
        for (int b = 0; b < dist[0].size(); b++)
            if (dist[a][b] <= limit)
                graph.addEdge(1 + a, 1 + dist.size() + b, 1);

    for (int b = 0; b < dist[0].size(); b++)
        graph.addEdge(1 + dist.size() + b, 1 + dist.size() + dist[0].size(), 1);

    return graph.maxFlow(0, 1 + dist.size() + dist[0].size()) >= dist.size() - maxLoss;
}

void solve(int test) {
    int aSize, bSize, maxLoss;
    cin >> aSize >> bSize >> maxLoss;

    vector<double> ax(aSize), ay(aSize);
    for (int i = 0; i < aSize; i++)
        cin >> ax[i] >> ay[i];

    vector<double> bx(bSize), by(bSize);
    for (int i = 0; i < bSize; i++)
        cin >> bx[i] >> by[i];

    if (ax.empty() || ay.empty()) {
        cout << "Impossible\n";
        return;
    }

    vector<vector<double>> dist(ax.size(), vector<double>(bx.size(), -1));
    for (int a = 0; a < ax.size(); a++)
        for (int b = 0; b < bx.size(); b++)
            dist[a][b] = hypot(ax[a] - bx[b], ay[a] - by[b]);

    double l = 0, r = 1e9;
    for (int i = 1; i < 200; i++) {
        double m = (l + r) / 2;
        if (can(dist, m, maxLoss))
            r = m;
        else
            l = m;
    }

    cout << "Case #" << test << ":\n";
    cout.precision(3);
    if (r == 1e9)
        cout << "Too bad.\n\n";
    else
        cout << fixed << r << "\n\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}