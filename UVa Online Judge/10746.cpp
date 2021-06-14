#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-9;

class Graph {
    struct Edge {
        int a, b;
        int capacity, flow;
        double cost;
        Edge(int a, int b, int capacity, double cost) : a(a), b(b), capacity(capacity), flow(0), cost(cost) {}
        int other(int v) const {
            return v == a ? b : a;
        }
        int capacityTo(int v) const {
            return v == b ? capacity - flow : flow;
        }
        double costTo(int v) const {
            return v == b ? cost : -cost;
        }
        void addFlowTo(int v, int f) {
            flow += (v == b ? f : -f);
        }
    };
    vector<Edge> edges;
    vector<double> distTo;
    vector<int> edgeTo;
    static inline const double INF = 1e9;
    void fordBellman(int v) {
        while (1) {
            bool update = 0;
            for (int i = 0; i < edges.size(); i++) {
                int a = edges[i].a, b = edges[i].b;
                if (edges[i].capacityTo(b) && distTo[a] != INF && distTo[b] > distTo[a] + edges[i].costTo(b) + EPS) {
                    distTo[b] = distTo[a] + edges[i].costTo(b);
                    edgeTo[b] = i;
                    update = 1;
                }
                if (edges[i].capacityTo(a) && distTo[b] != INF && distTo[a] > distTo[b] + edges[i].costTo(a) + EPS) {
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
    double addFlow(int from, int to, int flow) {
        double deltaCost = 0;
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
    void addEdge(int from, int to, int capacity, double cost) {
        edges.push_back(Edge(from, to, capacity, cost));
    }
    pair<double, int> minCostMaxFlow(int from, int to) {
        double cost = 0;
        int flow = 0;
        while (hasPath(from, to)) {
            int deltaFlow = bottleneckCapacity(from, to);
            cost += addFlow(from, to, deltaFlow);
            flow += deltaFlow;
        }
        return { cost, flow };
    }
};

bool solve() {
    int aSize, bSize;
    cin >> aSize >> bSize;

    if (!aSize && !bSize)
        return 0;

    Graph graph(1 + aSize + bSize + 1);

    for (int a = 0; a < aSize; a++)
        graph.addEdge(0, 1 + a, 1, 0);

    for (int a = 0; a < aSize; a++) {
        for (int b = 0; b < bSize; b++) {
            double cost;
            cin >> cost;
            graph.addEdge(1 + a, 1 + aSize + b, 1, cost);
        }
    }

    for (int b = 0; b < bSize; b++)
        graph.addEdge(1 + aSize + b, 1 + aSize + bSize, 1, 0);

    double res = graph.minCostMaxFlow(0, 1 + aSize + bSize).first / aSize + 0.0001;

    cout.precision(2);
    cout << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}