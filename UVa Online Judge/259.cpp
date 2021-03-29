#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

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

struct Graph {
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

bool solve() {
    string apps;
    string need;
    vector<string> edges;

    while (1) {
        string line;
        if (!getline(cin, line) || line.empty())
            break;
        apps += line[0];
        need += line[1];
        edges.push_back(line.substr(3, line.size() - 4));
    }

    if (apps.empty())
        return 0;

    Graph graph(1 + 26 + 10 + 1);
    int needFlow = 0;

    for (int i = 0; i < apps.size(); i++) {
        graph.addEdge(0, 1 + apps[i] - 'A', need[i] - '0');
        needFlow += need[i] - '0';

        for (char to : edges[i])
            graph.addEdge(1 + apps[i] - 'A', 1 + 26 + to - '0', 1);
    }

    for (int i = 0; i < 10; i++)
        graph.addEdge(1 + 26 + i, 1 + 26 + 10, 1);
        
    if (graph.maxFlow(0, 1 + 26 + 10) != needFlow) {
        cout << "!\n";
        return 1;
    }

    string res(10, '_');
    for (auto &[a, b, c, f] : graph.edges)
        if (1 <= a && a < 1 + 26 && f)
            res[b - 1 - 26] = a - 1 + 'A';

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}