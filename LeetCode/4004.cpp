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
    vector<vector<int>> graph;
    vector<long long> fordBellmanDist;
    vector<int> edgeTo;

    void initFordBellmanDist() {
        fordBellmanDist.assign(graph.size(), 0);

        while (1) {
            bool update = 0;

            for (Edge &edge : edges) {
                int a = edge.a, b = edge.b;

                if (edge.capacityTo(b) && fordBellmanDist[b] > fordBellmanDist[a] + edge.costTo(b)) {
                    fordBellmanDist[b] = fordBellmanDist[a] + edge.costTo(b);
                    update = 1;
                }

                if (edge.capacityTo(a) && fordBellmanDist[a] > fordBellmanDist[b] + edge.costTo(a)) {
                    fordBellmanDist[a] = fordBellmanDist[b] + edge.costTo(a);
                    update = 1;
                }
            }

            if (!update)
                break;
        }
    }

    bool hasPath(int start, int finish) {
        vector<long long> dist(graph.size(), 1e18);
        edgeTo.assign(graph.size(), -1);
        set<pair<long long, int>> q;

        dist[start] = 0;
        q.insert({ 0, start });

        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase(q.begin());

            for (int edgeIndex : graph[v]) {
                int to = edges[edgeIndex].other(v);
                if (!edges[edgeIndex].capacityTo(to))
                    continue;

                long long candidate = dist[v] + edges[edgeIndex].costTo(to) + fordBellmanDist[v] - fordBellmanDist[to];
                if (dist[to] > candidate) {
                    q.erase({ dist[to], to });
                    dist[to] = candidate;
                    edgeTo[to] = edgeIndex;
                    q.insert({ dist[to], to });
                }
            }
        }

        if (dist[finish] == 1e18)
            return 0;
        
        for (int v = 0; v < graph.size(); v++)
            if (dist[v] != 1e18)
                fordBellmanDist[v] += dist[v];
        return 1;
    }

    int getMinCapacity(int start, int finish) {
        int minCapacity = 1e9;
        for (int v = finish; v != start; v = edges[edgeTo[v]].other(v))
            minCapacity = min(minCapacity, edges[edgeTo[v]].capacityTo(v));
        return minCapacity;
    }

    long long addFlow(int start, int finish, int deltaFlow) {
        long long deltaCost = 0;
        for (int v = finish; v != start; v = edges[edgeTo[v]].other(v)) {
            edges[edgeTo[v]].addFlowTo(v, deltaFlow);
            deltaCost += 1LL * deltaFlow * edges[edgeTo[v]].costTo(v);
        }
        return deltaCost;
    }

public:
    Graph(int vertexCount) : graph(vertexCount) {}

    void addEdge(int from, int to, int capacity, int cost) {
        edges.push_back(Edge(from, to, capacity, cost));
        graph[from].push_back(edges.size() - 1);
        graph[to].push_back(edges.size() - 1);
    }

    pair<long long, long long> minCostMaxFlow(int start, int finish) {
        initFordBellmanDist();
        long long cost = 0, flow = 0;
        while (hasPath(start, finish)) {
            int deltaFlow = getMinCapacity(start, finish);
            cost += addFlow(start, finish, deltaFlow);
            flow += deltaFlow;
        }
        return { cost, flow };
    }
};

class Solution {
public:
    long long minMoves(vector<int> &a) {
        if (accumulate(a.begin(), a.end(), 0LL) < 0)
            return -1;

        Graph graph(1 + a.size() + 1);

        for (int v = 0; v < a.size(); v++) {
            if (a[v] > 0)
                graph.addEdge(0, 1 + v, a[v], 0);
            else if (a[v] < 0)
                graph.addEdge(1 + v, a.size() + 1, -a[v], 0);
            
            int to = (v + 1) % a.size();
            graph.addEdge(1 + v, 1 + to, 1e9, 1);
            graph.addEdge(1 + to, 1 + v, 1e9, 1);
        }

        return graph.minCostMaxFlow(0, 1 + a.size()).first;
    }
};