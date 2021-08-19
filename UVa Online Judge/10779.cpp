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
    int friendCount, stickerCount;
    cin >> friendCount >> stickerCount;

    vector<vector<int>> stickers(friendCount, vector<int>(stickerCount));
    for (vector<int> &stickers : stickers) {
        int count;
        cin >> count;
        for (int i = 0; i < count; i++) {
            int sticker;
            cin >> sticker;
            stickers[sticker - 1]++;
        }
    }

    Graph graph(1 + stickerCount + friendCount + 1);

    for (int s = 0; s < stickerCount; s++)
        graph.addEdge(0, 1 + s, stickers[0][s]);

    for (int f = 1; f < friendCount; f++) {
        for (int s = 0; s < stickerCount; s++) {
            if (stickers[f][s] == 0)
                graph.addEdge(1 + s, 1 + stickerCount + f, 1);
            if (stickers[f][s] > 1)
                graph.addEdge(1 + stickerCount + f, 1 + s, stickers[f][s] - 1);
        }
    }

    for (int s = 0; s < stickerCount; s++)
        graph.addEdge(1 + s, 1 + stickerCount + friendCount, 1);

    cout << "Case #" << test << ": " << graph.maxFlow(0, 1 + stickerCount + friendCount) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}