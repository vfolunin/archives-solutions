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
    int categoryCount, problemCount;
    cin >> categoryCount >> problemCount;

    if (!categoryCount)
        return 0;

    Graph graph(1 + categoryCount + problemCount + 1);
    int total = 0;
    
    for (int i = 0; i < categoryCount; i++) {
        int cap;
        cin >> cap;
        graph.addEdge(0, 1 + i, cap);
        total += cap;
    }

    for (int i = 0; i < problemCount; i++) {
        int k;
        cin >> k;

        for (int j = 0; j < k; j++) {
            int category;
            cin >> category;
            graph.addEdge(category, 1 + categoryCount + i, 1);
        }

        graph.addEdge(1 + categoryCount + i, 1 + categoryCount + problemCount, 1);
    }

    if (graph.maxFlow(0, 1 + categoryCount + problemCount) != total) {
        cout << "0\n";
        return 1;
    }

    vector<vector<int>> ans(categoryCount);
    for (auto &[a, b, c, f] : graph.edges)
        if (f && 1 <= a && a <= categoryCount)
            ans[a - 1].push_back(b - 1 - categoryCount);
    
    cout << "1\n";
    for (vector<int> &problems : ans)
        for (int i = 0; i < problems.size(); i++)
            cout << problems[i] + 1 << (i + 1 < problems.size() ? " " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}