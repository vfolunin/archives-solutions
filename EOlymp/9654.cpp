#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<set<int>> &graph, int v, vector<int> &l, vector<int> &r, vector<int> &order) {
    static int timer = 1;
    l[v] = timer++;
    order.push_back(v);
    for (int to : graph[v])
        if (!l[to])
            dfs(graph, to, l, r, order);
    r[v] = timer++;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<set<int>> graph(vertexCount);
    for (int a, b; cin >> a >> b; ) {
        a--;
        b--;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    vector<int> l(vertexCount), r(vertexCount), order;
    for (int v = 0; v < vertexCount; v++)
        if (!l[v])
            dfs(graph, v, l, r, order);

    for (int v : order)
        cout << "Vertex: " << v + 1 << ", Gray " << l[v] << ", Black " << r[v] << "\n";
}