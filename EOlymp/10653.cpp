#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<pair<int, int>>> &graph, int v, int p, int curXorSum, vector<int> &xorSum) {
    xorSum[v] = curXorSum;

    for (auto &[to, weight] : graph[v])
        if (to != p)
            dfs(graph, to, v, curXorSum ^ weight, xorSum);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<pair<int, int>>> graph(vertexCount);
    for (int i = 0; i < vertexCount - 1; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;
        a--;
        b--;
        graph[a].push_back({ b, weight });
        graph[b].push_back({ a, weight });
    }

    vector<int> xorSum(vertexCount);
    dfs(graph, 0, -1, 0, xorSum);

    long long count0 = count(xorSum.begin(), xorSum.end(), 0);
    long long count1 = xorSum.size() - count0;

    cout << count0 * count1;
}