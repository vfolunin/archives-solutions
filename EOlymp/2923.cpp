#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

unordered_set<int> dfs(vector<vector<int>> &graph, int v, vector<int> &a, vector<int> &res) {
    unordered_set<int> values = { a[v] };
    for (int to : graph[v]) {
        unordered_set<int> childValues = dfs(graph, to, a, res);
        if (values.size() < childValues.size())
            values.swap(childValues);
        values.insert(childValues.begin(), childValues.end());
    }
    res[v] = values.size();
    return values;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<vector<int>> graph(vertexCount);
    vector<int> a(vertexCount);
    int root = -1;

    for (int v = 0; v < vertexCount; v++) {
        int from;
        cin >> from >> a[v];

        if (from)
            graph[from - 1].push_back(v);
        else
            root = v;
    }

    vector<int> res(vertexCount);
    dfs(graph, root, a, res);

    for (int value : res)
        cout << value << " ";
}