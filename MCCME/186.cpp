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

        Edge(int a, int b, int capacity) :
            a(a), b(b), capacity(capacity), flow(0) {}

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
    vector<bool> visited;
    vector<int> edgeTo;

    void bfs(int v) {
        queue<int> q;
        visited[v] = 1;
        q.push(v);
        while (!q.empty()) {
            v = q.front();
            q.pop();
            for (int e : g[v]) {
                int to = edges[e].other(v);
                if (!visited[to] && edges[e].capacityTo(to)) {
                    edgeTo[to] = e;
                    visited[to] = 1;
                    q.push(to);
                }
            }
        }
    }

    bool hasPath(int from, int to) {
        fill(visited.begin(), visited.end(), 0);
        bfs(from);
        return visited[to];
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
    Graph(int vertexCount) {
        g.resize(vertexCount);
        visited.resize(vertexCount);
        edgeTo.resize(vertexCount);
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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<int> rowCapacity(h);
    for (int &capacity : rowCapacity)
        cin >> capacity;

    vector<int> colCapacity(w);
    for (int &capacity : colCapacity)
        cin >> capacity;

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> a[y][x];
            if (a[y][x] != -1) {
                rowCapacity[y] -= a[y][x];
                colCapacity[x] -= a[y][x];
            }
        }
    }

    if (*min_element(rowCapacity.begin(), rowCapacity.end()) < 0 ||
        *min_element(colCapacity.begin(), colCapacity.end()) < 0) {
        cout << -1;
        return 0;
    }

    Graph graph(1 + h + w + 1);

    for (int y = 0; y < h; y++)
        graph.addEdge(0, 1 + y, rowCapacity[y]);

    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            if (a[y][x] == -1)
                graph.addEdge(1 + y, 1 + h + x, 1e9);

    for (int x = 0; x < w; x++)
        graph.addEdge(1 + h + x, 1 + h + w, colCapacity[x]);

    graph.maxFlow(0, 1 + h + w);

    for (auto &[y, x, c, f] : graph.edges)
        if (y && x != 1 + h + w)
            a[y - 1][x - 1 - h] = f;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++)
            cout << a[y][x] << " ";
        cout << "\n";
    }
}