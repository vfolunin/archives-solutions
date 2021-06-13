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
        int a, b;
        long long capacity, flow, cost;
        Edge(int a, int b, long long capacity, long long cost) : a(a), b(b), capacity(capacity), flow(0), cost(cost) {}
        int other(int v) const {
            return v == a ? b : a;
        }
        long long capacityTo(int v) const {
            return v == b ? capacity - flow : flow;
        }
        long long costTo(int v) const {
            return v == b ? cost : -cost;
        }
        void addFlowTo(int v, long long f) {
            flow += (v == b ? f : -f);
        }
    };
    vector<Edge> edges;
    vector<long long> distTo;
    vector<int> edgeTo;
    static const long long INF = 1LL << 60;
    void fordBellman(int v) {
        while (1) {
            bool update = 0;
            for (int i = 0; i < edges.size(); i++) {
                int a = edges[i].a, b = edges[i].b;
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
    long long bottleneckCapacity(int from, int to) {
        long long bCapacity = INF;
        for (int v = to; v != from; v = edges[edgeTo[v]].other(v))
            bCapacity = min(bCapacity, edges[edgeTo[v]].capacityTo(v));
        return bCapacity;
    }
    long long addFlow(int from, int to, long long flow) {
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
    void addEdge(int from, int to, long long capacity, long long cost) {
        edges.push_back(Edge(from, to, capacity, cost));
    }
    pair<long long, long long> minCostMaxFlow(int from, int to) {
        long long cost = 0, flow = 0;
        while (hasPath(from, to)) {
            long long deltaFlow = bottleneckCapacity(from, to);
            cost += addFlow(from, to, deltaFlow);
            flow += deltaFlow;
        }
        return { cost, flow };
    }
};

bool solve() {
    int vertexCount, edgeCount;
    if (!(cin >> vertexCount >> edgeCount))
        return 0;
    
    Graph graph(vertexCount + 2);

    graph.addEdge(0, 1, 2, 0);

    for (int i = 0; i < edgeCount; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        
        graph.addEdge(a, b, 1, w);
        graph.addEdge(b, a, 1, w);
    }

    graph.addEdge(vertexCount, vertexCount + 1, 2, 0);

    auto [cost, flow] = graph.minCostMaxFlow(0, vertexCount + 1);

    if (flow == 2)
        cout << cost << "\n";
    else
        cout << "Back to jail\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}