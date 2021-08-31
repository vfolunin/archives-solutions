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

struct Data {
    int an = 0, bn = 0;
    vector<pair<int, int>> edges;
};

Data readData() {
    Data d;
    int edgeCount;

    if (!(cin >> d.an >> d.bn >> edgeCount))
        return d;

    d.edges.resize(edgeCount);
    for (auto &[a, b] : d.edges) {
        int index;
        cin >> index >> a >> b;
        a--;
        b--;
    }

    return d;
}

Graph computeMaxMatching(Data &d) {
    Graph g(1 + d.an + d.bn + 1);

    for (int i = 0; i < d.an; i++)
        g.addEdge(0, 1 + i, 1);

    for (auto &[a, b] : d.edges)
        g.addEdge(1 + a, 1 + d.an + b, 1);

    for (int i = 0; i < d.bn; i++)
        g.addEdge(1 + d.an + i, 1 + d.an + d.bn, 1);

    g.maxFlow(0, 1 + d.an + d.bn);

    return g;
}

vector<vector<int>> buildMVCGraph(Data &d, Graph &g) {
    vector<vector<int>> mg(d.an + d.bn);

    for (auto &[a, b, _, flow] : g.edges) {
        if (0 != a && b != 1 + d.an + d.bn) {
            if (flow)
                mg[b - 1].push_back(a - 1);
            else
                mg[a - 1].push_back(b - 1);
        }
    }

    return mg;
}

void dfs(vector<vector<int>> &g, int v, vector<int> &visited) {
    visited[v] = 1;
    for (int to : g[v])
        if (!visited[to])
            dfs(g, to, visited);
}

pair<vector<int>, vector<int>> computeMVC(Data &d, vector<vector<int>> &g) {
    set<int> startVertices;
    for (int i = 0; i < d.an; i++)
        startVertices.insert(i);

    for (auto &row : g)
        for (int to : row)
            startVertices.erase(to);

    vector<int> visited(d.an + d.bn);
    for (int v : startVertices)
        dfs(g, v, visited);

    vector<int> a;
    for (int i = 0; i < d.an; i++)
        if (!visited[i])
            a.push_back(i);

    vector<int> b;
    for (int i = 0; i < d.bn; i++)
        if (visited[d.an + i])
            b.push_back(i);

    return { a, b };
}

bool solve() {
    Data d = readData();
    if (!d.an)
        return 0;

    auto g = computeMaxMatching(d);
    auto gm = buildMVCGraph(d, g);
    auto [a, b] = computeMVC(d, gm);

    cout << a.size() + b.size() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}