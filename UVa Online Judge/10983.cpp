#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

class Graph {
    class Edge {
        int a, b, capacity, flow;
    public:
        Edge(int a, int b, int capacity) : a(a), b(b), capacity(capacity), flow(0) {}
        int other(int v) const {
            return v == a ? b : a;
        }
        int capacityTo(int v) const {
            return v == b ? capacity - flow : flow;
        }
        void addFlowTo(int v, int f) {
            flow += (v == b ? f : -f);
        }
    };
    vector<Edge> edges;
    vector<vector<int>> g;
    vector<bool> used;
    vector<int> edgeTo;
    void bfs(int v) {
        queue<int> q;
        used[v] = 1;
        q.push(v);
        while (!q.empty()) {
            v = q.front();
            q.pop();
            for (int e : g[v]) {
                int to = edges[e].other(v);
                if (!used[to] && edges[e].capacityTo(to)) {
                    edgeTo[to] = e;
                    used[to] = 1;
                    q.push(to);
                }
            }
        }
    }
    bool hasPath(int from, int to) {
        fill(used.begin(), used.end(), 0);
        bfs(from);
        return used[to];
    }
    int bottleneckCapacity(int from, int to) {
        int bCapacity = 1e9;
        for (int v = to; v != from; v = edges[edgeTo[v]].other(v))
            bCapacity = min(bCapacity, edges[edgeTo[v]].capacityTo(v));
        return bCapacity;
    }
    void addFlow(int from, int to, int flow) {
        for (int v = to; v != from; v = edges[edgeTo[v]].other(v))
            edges[edgeTo[v]].addFlowTo(v, flow);
    }
public:
    Graph(int verticesCount) {
        g.resize(verticesCount);
        used.resize(verticesCount);
        edgeTo.resize(verticesCount);
    }
    void addEdge(int from, int to, int capacity) {
        edges.push_back(Edge(from, to, capacity));
        g[from].push_back(edges.size() - 1);
        g[to].push_back(edges.size() - 1);
    }
    long long maxFlow(int from, int to) {
        long long flow = 0;
        while (hasPath(from, to)) {
            int deltaFlow = bottleneckCapacity(from, to);
            addFlow(from, to, deltaFlow);
            flow += deltaFlow;
        }
        return flow;
    }
};

struct Flight {
    int from, to, capacity, price, day;
};

bool can(int dayCount, vector<Flight> &flights, vector<int> &guestCount, int limit) {
    int cityCount = guestCount.size();
    Graph graph(1 + cityCount * dayCount);

    int targetFlow = 0;
    for (int c = 0; c < cityCount; c++) {
        graph.addEdge(0, 1 + c * dayCount, guestCount[c]);
        targetFlow += guestCount[c];
    }

    for (int c = 0; c < cityCount; c++)
        for (int d = 0; d + 1 < dayCount; d++)
            graph.addEdge(1 + c * dayCount + d, 1 + c * dayCount + d + 1, 1e9);

    for (auto &[from, to, capacity, price, day] : flights)
        if (price <= limit)
            graph.addEdge(1 + from * dayCount + day, 1 + to * dayCount + day + 1, capacity);

    return graph.maxFlow(0, cityCount * dayCount) == targetFlow;     
}

void solve(int test) {
    int cityCount, dayCount, flightCount;
    cin >> cityCount >> dayCount >> flightCount;
    dayCount++;

    vector<Flight> flights(flightCount);
    for (auto &[from, to, capacity, price, day] : flights) {
        cin >> from >> to >> capacity >> price >> day;
        from--;
        to--;
    }

    vector<int> guestCount(cityCount);
    for (int &count : guestCount)
        cin >> count;

    int l = -1, r = 100001;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(dayCount, flights, guestCount, m))
            r = m;
        else
            l = m;
    }

    cout << "Case #" << test << ": ";
    if (r < 100001)
        cout << r << "\n";
    else
        cout << "Impossible\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}