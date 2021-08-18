#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

class Graph {
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

int getId(map<string, int> &id, string &name) {
    if (!id.count(name))
        id[name] = id.size();
    return id[name];
}

void dfs(map<int, vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1;
    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited);
}

void solve(int test) {
    int recCount;
    cin >> recCount;

    map<string, int> id;
    vector<int> recId(recCount);

    for (int i = 0; i < recCount; i++) {
        string name;
        cin >> name;
        recId[i] = getId(id, name);
    }

    int deviceCount;
    cin >> deviceCount;

    vector<int> deviceId(deviceCount);

    for (int i = 0; i < deviceCount; i++) {
        string name;
        cin >> name >> name;
        deviceId[i] = getId(id, name);
    }

    int adapterCount;
    cin >> adapterCount;

    map<int, vector<int>> adapterGraph;

    for (int i = 0; i < adapterCount; i++) {
        string a, b;
        cin >> a >> b;
        adapterGraph[getId(id, a)].push_back(getId(id, b));
    }

    vector<vector<int>> adapterVisited(id.size(), vector<int>(id.size()));
    for (int v = 0; v < id.size(); v++)
        dfs(adapterGraph, v, adapterVisited[v]);

    Graph graph(1 + deviceCount + recCount + 1);

    for (int v = 0; v < deviceCount; v++)
        graph.addEdge(0, 1 + v, 1);

    for (int v = 0; v < deviceCount; v++)
        for (int to = 0; to < recCount; to++)
            if (adapterVisited[deviceId[v]][recId[to]])
                graph.addEdge(1 + v, 1 + deviceCount + to, 1);

    for (int v = 0; v < recCount; v++)
        graph.addEdge(1 + deviceCount + v, 1 + deviceCount + recCount, 1);

    if (test)
        cout << "\n";
    cout << deviceCount - graph.maxFlow(0, 1 + deviceCount + recCount) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}