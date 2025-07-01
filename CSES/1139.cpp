#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

set<int> dfs(vector<vector<int>> &graph, int v, int p, vector<int> &values, vector<int> &res) {
    set<int> valueSet = { values[v] };

    for (int to : graph[v]) {
        if (to == p)
            continue;

        set<int> toValues = dfs(graph, to, v, values, res);
        if (valueSet.size() < toValues.size())
            valueSet.swap(toValues);
        valueSet.insert(toValues.begin(), toValues.end());
    }

    res[v] = valueSet.size();
    return valueSet;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    vector<int> values(vertexCount);
    for (int &value : values)
        cin >> value;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < vertexCount - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> res(vertexCount);
    dfs(graph, 0, -1, values, res);

    for (int value : res)
        cout << value << " ";
}