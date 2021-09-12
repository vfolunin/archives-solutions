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

void solve(int test) {
    int catCount, dogCount, voterCount;
    cin >> catCount >> dogCount >> voterCount;

    vector<pair<int, int>> catVoters, dogVoters;
    for (int i = 0; i < voterCount; i++) {
        char t1, t2;
        int n1, n2;
        cin >> t1 >> n1 >> t2 >> n2;

        if (t1 == 'C')
            catVoters.push_back({ n1, n2 });
        else
            dogVoters.push_back({ n1, n2 });
    }

    Graph graph(1 + catVoters.size() + dogVoters.size() + 1);

    for (int v = 0; v < catVoters.size(); v++)
        graph.addEdge(0, 1 + v, 1);

    for (int a = 0; a < catVoters.size(); a++)
        for (int b = 0; b < dogVoters.size(); b++)
            if (catVoters[a].first == dogVoters[b].second || catVoters[a].second == dogVoters[b].first)
                graph.addEdge(1 + a, 1 + catVoters.size() + b, 1);

    for (int v = 0; v < dogVoters.size(); v++)
        graph.addEdge(1 + catVoters.size() + v, 1 + catVoters.size() + dogVoters.size(), 1);

    cout << voterCount - graph.maxFlow(0, 1 + catVoters.size() + dogVoters.size()) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}