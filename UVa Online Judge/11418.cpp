#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Edge {
    int a, b, capacity, flow;
    string text;
public:
    Edge(int a, int b, int capacity, const string &text) :
        a(a), b(b), capacity(capacity), flow(0), text(text) {}
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

struct Graph {
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
    void addEdge(int from, int to, int capacity, const string &text) {
        edges.push_back(Edge(from, to, capacity, text));
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

void capitalize(string &s) {
    s[0] = toupper(s[0]);
    for (int i = 1; i < s.size(); i++)
        s[i] = tolower(s[i]);
}

void solve(int test) {
    int problemCount;
    cin >> problemCount;

    Graph graph(1 + problemCount + problemCount + 1);
    for (int i = 0; i < problemCount; i++) {
        graph.addEdge(0, 1 + i, 1, "");
        graph.addEdge(1 + problemCount + i, 1 + problemCount + problemCount, 1, "");
    }

    for (int i = 0; i < problemCount; i++) {
        int edgeCount;
        cin >> edgeCount;

        for (int j = 0; j < edgeCount; j++) {
            string word;
            cin >> word;
            capitalize(word);

            if (word[0] - 'A' < problemCount)
                graph.addEdge(1 + i, 1 + problemCount + word[0] - 'A', 1, word);
        }
    }

    graph.maxFlow(0, 1 + problemCount + problemCount);
    vector<string> res;
    for (auto &[a, b, c, f, s] : graph.edges)
        if (f && !s.empty())
            res.push_back(s);
    sort(res.begin(), res.end());

    cout << "Case #" << test << ":\n";
    for (string &s : res)
        cout << s << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}