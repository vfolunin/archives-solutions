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
        long long flow = 0;
        while (hasPath(start, finish)) {
            int deltaFlow = bottleneckCapacity(start, finish);
            addFlow(start, finish, deltaFlow);
            flow += deltaFlow;
        }
        return flow;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w, price2, price1;
    cin >> h >> w >> price2 >> price1;

    vector<string> a(h);
    int freeCount = 0;
    for (string &row : a) {
        cin >> row;
        freeCount += count(row.begin(), row.end(), '*');
    }

    if (price2 >= 2 * price1) {
        cout << freeCount * price1;
        return 0;
    }

    Graph graph(1 + h * w + 1);

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (a[y][x] != '*')
                continue;

            if ((y + x) % 2 == 0)
                graph.addEdge(0, 1 + y * w + x, 1);
            else
                graph.addEdge(1 + y * w + x, 1 + h * w, 1);

            if (y + 1 < h && a[y + 1][x] == '*') {
                if ((y + x) % 2 == 0)
                    graph.addEdge(1 + y * w + x, 1 + (y + 1) * w + x, 1);
                else
                    graph.addEdge(1 + (y + 1) * w + x, 1 + y * w + x, 1);
            }

            if (x + 1 < w && a[y][x + 1] == '*') {
                if ((y + x) % 2 == 0)
                    graph.addEdge(1 + y * w + x, 1 + y * w + x + 1, 1);
                else
                    graph.addEdge(1 + y * w + x + 1, 1 + y * w + x, 1);
            }
        }
    }

    int count2 = graph.maxFlow(0, 1 + h * w);
    int count1 = freeCount - 2 * count2;

    cout << count2 * price2 + count1 * price1;
}