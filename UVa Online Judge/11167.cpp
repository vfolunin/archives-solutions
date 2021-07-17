#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Graph {
    struct Edge {
        int a, b, capacity, flow;
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

struct CoordinateCompressor {
    map<int, int> c;
    vector<int> d;
    void addCoordinate(int x) {
        c[x];
    }
    void prepare() {
        for (auto &[coord, compressed] : c) {
            compressed = d.size();
            d.push_back(coord);
        }
    }
    int size() {
        return d.size();
    }
    int compress(int x) {
        return c[x];
    }
    int decompress(int x) {
        return d[x];
    }
};

bool solve(int test) {
    int monkeyCount, placeCapacity;
    if (!(cin >> monkeyCount >> placeCapacity))
        return 0;

    vector<int> monkeyCapacity(monkeyCount);
    int totalMonkeyCapacity = 0;
    vector<pair<int, int>> monkeySegment(monkeyCount);

    CoordinateCompressor cc;

    for (int i = 0; i < monkeyCount; i++) {
        cin >> monkeyCapacity[i] >> monkeySegment[i].first >> monkeySegment[i].second;
        totalMonkeyCapacity += monkeyCapacity[i];
        cc.addCoordinate(monkeySegment[i].first);
        cc.addCoordinate(monkeySegment[i].second);
    }

    cc.prepare();

    Graph graph(1 + monkeyCount + cc.size() + 1);

    for (int i = 0; i < monkeyCount; i++) {
        graph.addEdge(0, 1 + i, monkeyCapacity[i]);
    
        int l = cc.compress(monkeySegment[i].first);
        int r = cc.compress(monkeySegment[i].second);
        for (int j = l; j < r; j++) {
            int width = cc.decompress(j + 1) - cc.decompress(j);
            graph.addEdge(1 + i, 1 + monkeyCount + j, width);
        }
    }

    for (int i = 0; i + 1 < cc.size(); i++) {
        int width = cc.decompress(i + 1) - cc.decompress(i);
        graph.addEdge(1 + monkeyCount + i, 1 + monkeyCount + cc.size(), width * placeCapacity);
    }

    bool can = graph.maxFlow(0, 1 + monkeyCount + cc.size()) == totalMonkeyCapacity;

    cout << "Case " << test << ": " << (can ? "Yes\n" : "No\n");
    if (!can)
        return 1;

    vector<priority_queue<pair<int, int>>> slots(cc.size());
    for (int i = 0; i + 1 < cc.size(); i++) {
        int l = cc.decompress(i), r = cc.decompress(i + 1);
        for (int coord = l; coord < r; coord++)
            slots[i].push({ placeCapacity, coord });
    }

    vector<vector<int>> coords(monkeyCount);
    for (auto &[a, b, _, f] : graph.edges) {
        if (f && 0 < a && a < 1 + monkeyCount) {
            int monkey = a - 1, slot = b - 1 - monkeyCount;
            for (int i = 0; i < f; i++) {
                auto [count, coord] = slots[slot].top();
                slots[slot].pop();
                coords[monkey].push_back(coord);
                slots[slot].push({ count - 1, coord });
            }
        }
    }

    for (int i = 0; i < monkeyCount; i++) {
        sort(coords[i].begin(), coords[i].end());
        vector<pair<int, int>> segments;
        for (int coord : coords[i]) {
            if (!segments.empty() && segments.back().second == coord)
                segments.back().second++;
            else
                segments.push_back({ coord, coord + 1 });
        }

        cout << segments.size();
        for (auto &[l, r] : segments)
            cout << " (" << l << "," << r << ")";
        cout << "\n";
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int test = 1; solve(test); test++);
}