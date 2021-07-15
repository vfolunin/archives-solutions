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

vector<vector<int>> bfs(vector<string> &a, int y, int x) {
    vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
    queue<int> q;

    dist[y][x] = 0;
    q.push(y);
    q.push(x);

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        int dy[] = { -1, 0, 1, 0 };
        int dx[] = { 0, 1, 0, -1 };
        
        for (int d = 0; d < 4; d++) {
            int ty = y + dy[d], tx = x + dx[d];
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] != '#' && dist[ty][tx] == 1e9) {
                dist[ty][tx] = dist[y][x] + 1;
                q.push(ty);
                q.push(tx);
            }
        }
    }

    return dist;
}

void solve(int test) {
    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    vector<pair<int, int>> start, finish;
    for (int y = 0; y < h; y++) {
        cin >> a[y];
        for (int x = 0; x < w; x++) {
            if (a[y][x] == 'B')
                start.push_back({ y, x });
            if (a[y][x] == 'X')
                finish.push_back({ y, x });
        }
    }

    Graph graph(1 + start.size() + finish.size() + 1);

    for (int i = 0; i < start.size(); i++)
        graph.addEdge(0, 1 + i, 1, 0);

    for (int i = 0; i < start.size(); i++) {
        auto &[sy, sx] = start[i];
        vector<vector<int>> dist = bfs(a, sy, sx);
        for (int j = 0; j < finish.size(); j++) {
            auto &[fy, fx] = finish[j];
            graph.addEdge(1 + i, 1 + start.size() + j, 1, dist[fy][fx]);
        }
    }

    for (int i = 0; i < finish.size(); i++)
        graph.addEdge(1 + start.size() + i, 1 + start.size() + finish.size(), 1, 0);

    long long res = graph.minCostMaxFlow(0, 1 + start.size() + finish.size()).first;

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}