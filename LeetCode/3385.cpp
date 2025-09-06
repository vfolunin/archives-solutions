class Graph {
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

public:
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

class Solution {
public:
    int findMinimumTime(vector<int> &a) {
        Graph graph(1 + a.size() + a.size() + 1);

        for (int v = 0; v < a.size(); v++)
            graph.addEdge(0, 1 + v, 1, 0);
        
        for (int v = 0; v < a.size(); v++)
            for (int to = 0; to < a.size(); to++)
                graph.addEdge(1 + v, 1 + a.size() + to, 1, (a[to] + v) / (v + 1));
        
        for (int v = 0; v < a.size(); v++)
            graph.addEdge(1 + a.size() + v, 1 + a.size() + a.size(), 1, 0);
        
        return graph.minCostMaxFlow(0, 1 + a.size() + a.size()).first;
    }
};