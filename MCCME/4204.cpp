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
    vector<bool> visited;
    vector<int> edgeTo;

    void bfs(int start) {
        queue<int> q;
        visited[start] = 1;
        q.push(start);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int e : graph[v]) {
                int to = edges[e].other(v);
                if (!visited[to] && edges[e].capacityTo(to)) {
                    edgeTo[to] = e;
                    visited[to] = 1;
                    q.push(to);
                }
            }
        }
    }

    bool hasPath(int start, int finish) {
        visited.assign(visited.size(), 0);
        bfs(start);
        return visited[finish];
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
        graph(vertexCount), visited(vertexCount), edgeTo(vertexCount) {}

    void addEdge(int from, int to, int capacity) {
        edges.push_back(Edge(from, to, capacity));
        graph[from].push_back(edges.size() - 1);
        graph[to].push_back(edges.size() - 1);
    }

    long long maxFlow(int start, int finish) {
        long long flow = 0;
        while (hasPath(start, finish)) {
            int deltaFlow = bottleneckCapacity(start, finish);
            addFlow(start, finish, deltaFlow);
            flow += deltaFlow;
        }
        return flow;
    }
};

struct Data {
    int vertexCountA = 0, vertexCountB = 0;
    set<pair<int, int>> badEdges;
};

Data readData() {
    Data data;
    cin >> data.vertexCountA >> data.vertexCountB;

    for (int a = 0; a < data.vertexCountA; a++) {
        while (1) {
            int b;
            cin >> b;

            if (!b)
                break;

            data.badEdges.insert({ a, b - 1 });
        }
    }

    return data;
}

Graph computeMaxMatching(Data &data) {
    Graph graph(1 + data.vertexCountA + data.vertexCountB + 1);

    for (int a = 0; a < data.vertexCountA; a++)
        graph.addEdge(0, 1 + a, 1);

    for (int a = 0; a < data.vertexCountA; a++)
        for (int b = 0; b < data.vertexCountB; b++)
            if (!data.badEdges.count({ a, b }))
                graph.addEdge(1 + a, 1 + data.vertexCountA + b, 1);

    for (int b = 0; b < data.vertexCountB; b++)
        graph.addEdge(1 + data.vertexCountA + b, 1 + data.vertexCountA + data.vertexCountB, 1);

    graph.maxFlow(0, 1 + data.vertexCountA + data.vertexCountB);

    return graph;
}

vector<vector<int>> buildMvcGraph(Data &data, Graph &graph) {
    vector<vector<int>> mvcGraph(data.vertexCountA + data.vertexCountB);

    for (auto &[a, b, capacity, flow] : graph.edges) {
        if (0 != a && b != 1 + data.vertexCountA + data.vertexCountB) {
            if (flow)
                mvcGraph[b - 1].push_back(a - 1);
            else
                mvcGraph[a - 1].push_back(b - 1);
        }
    }

    return mvcGraph;
}

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1;
    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited);
}

pair<vector<int>, vector<int>> computeMIS(Data &data, vector<vector<int>> &mvcGraph) {
    set<int> startVertices;
    for (int i = 0; i < data.vertexCountA; i++)
        startVertices.insert(i);

    for (auto &row : mvcGraph)
        for (int to : row)
            startVertices.erase(to);

    vector<int> visited(data.vertexCountA + data.vertexCountB);
    for (int v : startVertices)
        dfs(mvcGraph, v, visited);

    vector<int> a;
    for (int v = 0; v < data.vertexCountA; v++)
        if (visited[v])
            a.push_back(v);

    vector<int> b;
    for (int v = 0; v < data.vertexCountB; v++)
        if (!visited[data.vertexCountA + v])
            b.push_back(v);

    return { a, b };
}

void solve() {
    Data data = readData();
    Graph graph = computeMaxMatching(data);
    vector<vector<int>> mvcGraph = buildMvcGraph(data, graph);
    auto [a, b] = computeMIS(data, mvcGraph);

    cout << a.size() + b.size() << "\n";
    cout << a.size() << " " << b.size() << "\n";
    for (int v : a)
        cout << v + 1 << " ";
    cout << "\n";
    for (int v : b)
        cout << v + 1 << " ";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}