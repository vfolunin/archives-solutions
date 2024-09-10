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
        int a, b, capacity, flow = 0;

        Edge(int a, int b, int capacity) :
            a(a), b(b), capacity(capacity) {}

        int other(int v) const {
            return v == a ? b : a;
        }

        int capacityTo(int v) const {
            return v == b ? capacity - flow : flow;
        }

        void addFlowTo(int v, int deltaFlow) {
            flow += (v == b ? deltaFlow : -deltaFlow);
        }
    };

    vector<Edge> edges;
    vector<vector<int>> graph;
    vector<int> dist, edgeTo, index;

    bool bfs(int start, int finish) {
        dist.assign(graph.size(), 1e9);
        queue<int> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int e : graph[v]) {
                int to = edges[e].other(v);
                if (edges[e].capacityTo(to) && dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }

        return dist[finish] != 1e9;
    }

    bool dfs(int v, int finish) {
        if (v == finish)
            return 1;

        for (; index[v] < graph[v].size(); index[v]++) {
            int e = graph[v][index[v]], to = edges[e].other(v);
            if (edges[e].capacityTo(to) && dist[to] == dist[v] + 1 && dfs(to, finish)) {
                edgeTo[to] = e;
                return 1;
            }
        }

        return 0;
    }

    int bottleneckCapacity(int start, int finish) {
        int bCapacity = 1e9;
        for (int v = finish; v != start; v = edges[edgeTo[v]].other(v))
            bCapacity = min(bCapacity, edges[edgeTo[v]].capacityTo(v));
        return bCapacity;
    }

    void addFlow(int start, int finish, int deltaFlow) {
        for (int v = finish; v != start; v = edges[edgeTo[v]].other(v))
            edges[edgeTo[v]].addFlowTo(v, deltaFlow);
    }

public:
    Graph(int vertexCount) :
        graph(vertexCount), dist(vertexCount), edgeTo(vertexCount), index(vertexCount) {}

    void addEdge(int from, int to, int capacity) {
        edges.push_back(Edge(from, to, capacity));
        graph[from].push_back(edges.size() - 1);
        graph[to].push_back(edges.size() - 1);
    }

    long long maxFlow(int start, int finish) {
        long long flow = 0;
        while (bfs(start, finish)) {
            index.assign(graph.size(), 0);
            while (dfs(start, finish)) {
                int deltaFlow = bottleneckCapacity(start, finish);
                addFlow(start, finish, deltaFlow);
                flow += deltaFlow;
            }
        }
        return flow;
    }
};

void solve() {
    int n;
    cin >> n;

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> t(n), x1(n), y1(n), x2(n), y2(n);
    for (int i = 0; i < n; i++) {
        int h, m;
        char c;
        cin >> h >> c >> m >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        t[i] = h * 60 + m;
    }

    Graph graph(1 + n + n + 1);
    for (int i = 0; i < n; i++) {
        graph.addEdge(0, 1 + i, 1);

        for (int j = 0; j < n; j++)
            if (t[i] + abs(x1[i] - x2[i]) + abs(y1[i] - y2[i]) + abs(x2[i] - x1[j]) + abs(y2[i] - y1[j]) < t[j])
                graph.addEdge(1 + i, 1 + n + j, 1);

        graph.addEdge(1 + n + i, 1 + n + n, 1);
    }

    int res = n - graph.maxFlow(0, 1 + n + n);

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}