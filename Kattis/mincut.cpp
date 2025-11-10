#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

class Graph {
    struct Edge {
        int a, b, capacity, flow = 0;

        Edge(int a, int b, int capacity) :
            a(a), b(b), capacity(capacity) {}

        int other(int v) const {
            return v == b ? a : b;
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
    vector<int> visited, edgeTo;

    bool hasPath(int start, int finish) {
        visited.assign(graph.size(), 0);
        edgeTo.assign(graph.size(), -1);
        queue<int> q;

        visited[start] = 1;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int edgeIndex : graph[v]) {
                int to = edges[edgeIndex].other(v);
                if (!visited[to] && edges[edgeIndex].capacityTo(to)) {
                    visited[to] = 1;
                    edgeTo[to] = edgeIndex;
                    q.push(to);
                }
            }
        }

        return visited[finish];
    }

    int getMinCapacity(int start, int finish) {
        int minCapacity = 1e9;
        for (int v = finish; v != start; v = edges[edgeTo[v]].other(v))
            minCapacity = min(minCapacity, edges[edgeTo[v]].capacityTo(v));
        return minCapacity;
    }

    void addFlow(int start, int finish, int deltaFlow) {
        for (int v = finish; v != start; v = edges[edgeTo[v]].other(v))
            edges[edgeTo[v]].addFlowTo(v, deltaFlow);
    }

    void dfs(int v, unordered_set<int> &cut) {
        cut.insert(v);
        for (int edgeIndex : graph[v]) {
            int to = edges[edgeIndex].other(v);
            if (edges[edgeIndex].capacityTo(to) && !cut.count(to))
                dfs(to, cut);
        }
    }

public:
    Graph(int vertexCount) : graph(vertexCount) {}

    void addEdge(int from, int to, int capacity) {
        edges.push_back(Edge(from, to, capacity));
        graph[from].push_back(edges.size() - 1);
        graph[to].push_back(edges.size() - 1);
    }

    long long maxFlow(int start, int finish) {
        long long flow = 0;
        while (hasPath(start, finish)) {
            int deltaFlow = getMinCapacity(start, finish);
            addFlow(start, finish, deltaFlow);
            flow += deltaFlow;
        }
        return flow;
    }

    unordered_set<int> minCut(int from, int to) {
        maxFlow(from, to);
        unordered_set<int> cut;
        dfs(from, cut);
        return cut;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount, source, sink;
    cin >> vertexCount >> edgeCount >> source >> sink;

    Graph graph(vertexCount);

    for (int i = 0; i < edgeCount; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;

        graph.addEdge(a, b, weight);
    }

    unordered_set<int> minCut = graph.minCut(source, sink);

    cout << minCut.size() << "\n";
    for (int v : minCut)
        cout << v << "\n";
}