#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Student {
    int height;
    string sex, music, sport;

    bool matches(Student &that) {
        return abs(height - that.height) <= 40 && sex != that.sex && music == that.music && sport != that.sport;
    }
};

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

void solve() {
    int studentCount;
    cin >> studentCount;

    vector<Student> a, b;
    for (int i = 0; i < studentCount; i++) {
        Student student;
        cin >> student.height >> student.sex >> student.music >> student.sport;
        if (student.sex == "M")
            a.push_back(student);
        else
            b.push_back(student);
    }

    Graph graph(1 + a.size() + b.size() + 1);

    for (int v = 0; v < a.size(); v++)
        graph.addEdge(0, 1 + v, 1);

    for (int av = 0; av < a.size(); av++)
        for (int bv = 0; bv < b.size(); bv++)
            if (a[av].matches(b[bv]))
                graph.addEdge(1 + av, 1 + a.size() + bv, 1);

    for (int v = 0; v < b.size(); v++)
        graph.addEdge(1 + a.size() + v, 1 + a.size() + b.size(), 1);

    cout << studentCount - graph.maxFlow(0, 1 + a.size() + b.size()) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}