#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

class Graph {
    class Edge {
        int _a, _b, capacity, flow, cost;
    public:
        Edge(int a, int b, int capacity, int cost) : _a(a), _b(b), capacity(capacity), flow(0), cost(cost) {}
        int a() const {
            return _a;
        }
        int b() const {
            return _b;
        }
        int other(int v) const {
            return v == _a ? _b : _a;
        }
        int capacityTo(int v) const {
            return v == _b ? capacity - flow : flow;
        }
        int costTo(int v) const {
            return v == _b ? cost : -cost;
        }
        void addFlowTo(int v, int f) {
            flow += (v == _b ? f : -f);
        }
    };
    vector<Edge> edges;
    vector<int> distTo;
    vector<int> edgeTo;
    static const int INF = 1 << 30;
    void fordBellman(int v) {
        while (1) {
            bool update = 0;
            for (int i = 0; i < edges.size(); i++) {
                int a = edges[i].a(), b = edges[i].b();
                if (edges[i].capacityTo(b) && distTo[a] != INF && distTo[b] > distTo[a] + edges[i].costTo(b)) {
                    distTo[b] = distTo[a] + edges[i].costTo(b);
                    edgeTo[b] = i;
                    update = 1;
                }
                if (edges[i].capacityTo(a) && distTo[b] != INF && distTo[a] > distTo[b] + edges[i].costTo(a)) {
                    distTo[a] = distTo[b] + edges[i].costTo(a);
                    edgeTo[a] = i;
                    update = 1;
                }
            }
            if (!update)
                break;
        }
    }
    bool hasPath(int from, int to) {
        fill(distTo.begin(), distTo.end(), INF);
        distTo[from] = 0;
        fordBellman(from);
        return distTo[to] != INF;
    }
    int bottleneckCapacity(int from, int to) {
        int bCapacity = INF;
        for (int v = to; v != from; v = edges[edgeTo[v]].other(v))
            bCapacity = min(bCapacity, edges[edgeTo[v]].capacityTo(v));
        return bCapacity;
    }
    long long addFlow(int from, int to, int flow) {
        long long deltaCost = 0;
        for (int v = to; v != from; v = edges[edgeTo[v]].other(v)) {
            edges[edgeTo[v]].addFlowTo(v, flow);
            deltaCost += flow * edges[edgeTo[v]].costTo(v);
        }
        return deltaCost;
    }
public:
    Graph(int verticesCount) {
        distTo.resize(verticesCount);
        edgeTo.resize(verticesCount);
    }
    void addEdge(int from, int to, int capacity, int cost) {
        edges.push_back(Edge(from, to, capacity, cost));
    }
    pair<long long, long long> minCostMaxFlow(int from, int to) {
        long long cost = 0, flow = 0;
        while (hasPath(from, to)) {
            int deltaFlow = bottleneckCapacity(from, to);
            cost += addFlow(from, to, deltaFlow);
            flow += deltaFlow;
        }
        return make_pair(cost, flow);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount, from, to;
    cin >> vertexCount >> edgeCount >> from >> to;

    Graph graph(vertexCount);

    for (int i = 0; i < edgeCount; i++) {
        int a, b, capacity, cost;
        cin >> a >> b >> capacity >> cost;
        graph.addEdge(a, b, capacity, cost);
    }

    auto [cost, flow] = graph.minCostMaxFlow(from, to);

    cout << flow << " " << cost;
}