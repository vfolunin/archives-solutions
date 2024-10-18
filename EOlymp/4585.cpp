#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    struct Edge {
        int a, b, capacity, flow = 0, cost;

        Edge(int a, int b, int capacity, int cost) :
            a(a), b(b), capacity(capacity), cost(cost) {}

        int other(int v) const {
            return v == a ? b : a;
        }

        int capacityTo(int v) const {
            return v == b ? capacity - flow : flow;
        }

        int costTo(int v) const {
            return v == b ? cost : -cost;
        }

        void addFlowTo(int v, int deltaFlow) {
            flow += (v == b ? deltaFlow : -deltaFlow);
        }
    };

    vector<Edge> edges;
    vector<int> distTo;
    vector<int> edgeTo;
    static const int INF = 1e9;

    void fordBellman(int start) {
        fill(distTo.begin(), distTo.end(), INF);
        distTo[start] = 0;
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

    bool hasPath(int start, int finish) {
        fordBellman(start);
        return distTo[finish] != INF;
    }

    int bottleneckCapacity(int start, int finish) {
        int bCapacity = INF;
        for (int v = finish; v != start; v = edges[edgeTo[v]].other(v))
            bCapacity = min(bCapacity, edges[edgeTo[v]].capacityTo(v));
        return bCapacity;
    }

    long long addFlow(int start, int finish, int deltaFlow) {
        long long deltaCost = 0;
        for (int v = finish; v != start; v = edges[edgeTo[v]].other(v)) {
            edges[edgeTo[v]].addFlowTo(v, deltaFlow);
            deltaCost += deltaFlow * edges[edgeTo[v]].costTo(v);
        }
        return deltaCost;
    }

    Graph(int vertexCount) :
        distTo(vertexCount), edgeTo(vertexCount) {}

    void addEdge(int from, int to, int capacity, int cost) {
        edges.push_back(Edge(from, to, capacity, cost));
    }

    pair<long long, long long> minCostMaxFlow(int start, int finish) {
        long long cost = 0, flow = 0;
        while (hasPath(start, finish)) {
            int deltaFlow = bottleneckCapacity(start, finish);
            cost += addFlow(start, finish, deltaFlow);
            flow += deltaFlow;
        }
        return { cost, flow };
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    Graph graph(1 + size + size + 1);

    for (int v = 0; v < size; v++)
        graph.addEdge(0, 1 + v, 1, 0);

    for (int a = 0; a < size; a++) {
        for (int b = 0; b < size; b++) {
            int cost;
            cin >> cost;

            graph.addEdge(1 + a, 1 + size + b, 1, cost);
        }
    }

    for (int v = 0; v < size; v++)
        graph.addEdge(1 + size + v, 1 + size + size, 1, 0);

    cout << graph.minCostMaxFlow(0, 1 + size + size).first << "\n";
    for (int v = 0; v < size; v++) {
        for (auto &[a, b, capacity, flow, cost] : graph.edges) {
            if (a == 1 + v && flow) {
                cout << b - size << " ";
                break;
            }
        }
    }
}