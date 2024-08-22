#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> read() {
    string s;
    getline(cin, s);
    stringstream ss(s);

    vector<int> res;
    for (int value; ss >> value; )
        res.push_back(value);
    return res;
}

struct Graph {
    vector<vector<int>> graph;
    vector<int> visited;
    vector<int> order;

    Graph(int vertexCount) : graph(vertexCount), visited(vertexCount) {}

    void addEdge(int a, int b) {
        graph[a].push_back(b);
    }

    void dfs(int v) {
        visited[v] = 1;
        for (int to : graph[v])
            if (!visited[to])
                dfs(to);
        order.push_back(v);
    }

    vector<int> topsort() {
        dfs(0);
        return order;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> price = read();

    int vertexCount = price.size();
    Graph graph(vertexCount);

    for (int v = 0; v < vertexCount; v++)
        for (int to : read())
            graph.addEdge(v, to - 1);

    long long res = 0;
    for (int v : graph.topsort())
        res += price[v];

    cout << res;
}