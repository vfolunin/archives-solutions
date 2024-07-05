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
        for (auto &[a, b, capacity, flow] : edges)
            flow = 0;
        long long flow = 0;
        while (hasPath(start, finish)) {
            int deltaFlow = bottleneckCapacity(start, finish);
            addFlow(start, finish, deltaFlow);
            flow += deltaFlow;
        }
        return flow;
    }

    long long minCut(int from, int to) {
        maxFlow(from, to);
        long long cut = 0;
        for (int i = 0; i < edges.size(); i++)
            if (visited[edges[i].a] && !visited[edges[i].b])
                cut += edges[i].capacity;
        return cut;
    }

    long long globalMinCut() {
        long long cut = 1e18;
        for (int v = 1; v < graph.size(); v++)
            cut = min(cut, minCut(0, v));
        return cut;
    }
};

bool solve() {
    int vertexCount;
    if (!(cin >> vertexCount))
        return 0;

    Graph graph(vertexCount);
    for (int a = 0; a < vertexCount; a++) {
        for (int b = 0; b < vertexCount; b++) {
            char capacity;
            cin >> capacity;

            if (capacity > '0')
                graph.addEdge(a, b, capacity - '0');
        }
    }

    cout << graph.globalMinCut() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}