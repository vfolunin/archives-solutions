#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<vector<int>> &graph, int v, vector<int> &price) {
    if (graph[v].empty())
        return price[v];

    int res = 1e9;
    for (int to : graph[v])
        res = min(res, dfs(graph, to, price) + price[v]);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    vector<int> price(vertexCount);

    for (int v = 0; v < vertexCount; v++) {
        int degree;
        cin >> price[v] >> degree;

        for (int i = 0; i < degree; i++) {
            int to;
            cin >> to;

            graph[v].push_back(to - 1);
        }
    }

    cout << dfs(graph, 0, price);
}