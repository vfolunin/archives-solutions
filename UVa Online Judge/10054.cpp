#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void euler(map<int, multiset<int>> &graph, int v, vector<int> &cycle) {
    while (!graph[v].empty()) {
        int to = *graph[v].begin();
        graph[v].erase(graph[v].find(to));
        graph[to].erase(graph[to].find(v));
        euler(graph, to, cycle);
    }
    cycle.push_back(v);
}

void solve(int test) {
    int edgeCount;
    cin >> edgeCount;

    map<int, multiset<int>> graph;
    map<int, int> degree;
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
        degree[a]++;
        degree[b]++;
    }

    bool isEulerian = 1;
    for (auto &[_, d] : degree)
        isEulerian &= d % 2 == 0;

    vector<int> cycle;
    euler(graph, graph.begin()->first, cycle);
    reverse(cycle.begin(), cycle.end());
    isEulerian &= cycle.size() == edgeCount + 1;
    
    if (test > 1)
        cout << "\n";
    cout << "Case #" << test << "\n";
    if (!isEulerian) {
        cout << "some beads may be lost\n";
    } else {
        for (int i = 0; i + 1 < cycle.size(); i++)
            cout << cycle[i] << " " << cycle[i + 1] << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}