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

void eulerRec(vector<multiset<int>> &graph, int v, vector<int> &cycle) {
    while (!graph[v].empty()) {
        int to = *graph[v].begin();
        graph[v].erase(graph[v].find(to));
        eulerRec(graph, to, cycle);
    }
    cycle.push_back(v);
}

vector<int> euler(vector<multiset<int>> &graph) {
    vector<int> cycle;
    eulerRec(graph, 0, cycle);
    reverse(cycle.begin(), cycle.end());
    return cycle;
}

void solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> edges;
    vector<int> degree(vertexCount);

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        char type;
        cin >> a >> b >> type;
        a--;
        b--;
        degree[a]++;
        degree[b]++;
        edges.push_back({ a, b, type == 'U' });
    }

    if (test)
        cout << "\n";

    for (int d : degree) {
        if (d % 2) {
            cout << "No euler circuit exist\n";
            return;
        }
    }

    Graph graph(1 + edgeCount + vertexCount + 1);

    for (int i = 0; i < edgeCount; i++)
        graph.addEdge(0, 1 + i, 1);

    for (int i = 0; i < edgeCount; i++) {
        graph.addEdge(1 + i, 1 + edgeCount + edges[i][1], 1);
        if (edges[i][2])
            graph.addEdge(1 + i, 1 + edgeCount + edges[i][0], 1);
    }

    for (int i = 0; i < vertexCount; i++)
        graph.addEdge(1 + edgeCount + i, 1 + edgeCount + vertexCount, degree[i] / 2);

    if (graph.maxFlow(0, 1 + edgeCount + vertexCount) != edgeCount) {
        cout << "No euler circuit exist\n";
        return;
    }

    vector<multiset<int>> eulerGraph(vertexCount);
    for (auto &[a, b, _, flow] : graph.edges) {
        if (a && b != 1 + edgeCount + vertexCount && flow) {
            int eb = b - 1 - edgeCount;
            int ea = edges[a - 1][0] + edges[a - 1][1] - eb;
            eulerGraph[ea].insert(eb);
        }
    }

    vector<int> tour = euler(eulerGraph);

    for (int i = 0; i < tour.size(); i++)
        cout << tour[i] + 1 << (i + 1 < tour.size() ? " " : "\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}