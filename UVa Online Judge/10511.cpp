#include <iostream>
#include <sstream>
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

int getId(map<string, int> &id, vector<string> &names, string &name) {
    if (!id.count(name)) {
        id[name] = id.size();
        names.push_back(name);
    }
    return id[name];
}

void solve(int test) {
    vector<string> ns, ps, cs;
    map<string, int> nid, pid, cid;
    vector<vector<int>> edges;

    while (1) {
        string line;
        if (!getline(cin, line) || line.empty())
            break;

        stringstream ss(line);

        string name, party, club;
        ss >> name >> party;

        while (ss >> club)
            edges.push_back({ getId(cid, cs, club), getId(nid, ns, name), getId(pid, ps, party) });
    }

    int nk = ns.size(), pk = ps.size(), ck = cs.size();

    Graph graph(1 + ck + nk + nk + pk + 1);

    for (int c = 0; c < ck; c++)
        graph.addEdge(0, 1 + c, 1);

    for (vector<int> &edge : edges) {
        graph.addEdge(1 + edge[0], 1 + ck + edge[1], 1);
        graph.addEdge(1 + ck + nk + edge[1], 1 + ck + nk + nk + edge[2], 1);
    }

    for (int n = 0; n < nk; n++)
        graph.addEdge(1 + ck + n, 1 + ck + nk + n, 1);

    for (int p = 0; p < pk; p++)
        graph.addEdge(1 + ck + nk + nk + p, 1 + ck + nk + nk + pk, (ck - 1) / 2);

    if (test)
        cout << "\n";

    if (graph.maxFlow(0, 1 + ck + nk + nk + pk) != ck) {
        cout << "Impossible.\n";
        return;
    }

    for (auto &[a, b, capacity, flow] : graph.edges)
        if (flow && 1 <= a && a < 1 + ck)
            cout << ns[b - 1 - ck] << " " << cs[a - 1] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore(2);

    for (int i = 0; i < n; i++)
        solve(i);
}