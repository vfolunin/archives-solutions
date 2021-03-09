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
public:
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

void solve(int test) {
    int height, width;
    cin >> height >> width;

    vector<int> rowSum(height);
    for (int &s : rowSum)
        cin >> s;
    for (int i = height - 1; i > 0; i--)
        rowSum[i] -= rowSum[i - 1];

    vector<int> colSum(width);
    for (int &s : colSum)
        cin >> s;
    for (int i = width - 1; i > 0; i--)
        colSum[i] -= colSum[i - 1];

    Graph graph(1 + height + width + 1);
    for (int i = 0; i < height; i++)
        graph.addEdge(0, 1 + i, rowSum[i] - width);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            graph.addEdge(1 + i, 1 + height + j, 19);
    for (int i = 0; i < width; i++)
        graph.addEdge(1 + height + i, 1 + height + width, colSum[i] - height);

    graph.maxFlow(0, 1 + height + width);

    vector<vector<int>> res(height, vector<int>(width));
    for (auto &[a, b, c, f] : graph.edges)
        if (a != 0 && b != 1 + height + width)
            res[a - 1][b - 1 - height] = f;

    cout << "Matrix " << test << "\n";
    for (vector<int> &row : res)
        for (int j = 0; j < width; j++)
            cout << row[j] + 1 << (j + 1 < width ? ' ' : '\n');
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}