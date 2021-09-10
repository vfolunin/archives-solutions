#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, vector<set<int>> &descendants) {
    visited[v] = 1;
    for (int to : graph[v]) {
        if (!visited[to])
            dfs(graph, to, visited, descendants);
        descendants[v].insert(to);
        descendants[v].insert(descendants[to].begin(), descendants[to].end());
    }
}

bool solve() {
    int vertexCount, edgeCount, queryCount;
    if (!(cin >> vertexCount >> edgeCount >> queryCount))
        return 0;

    vector<int> age(vertexCount);
    for (int &a : age)
        cin >> a;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        graph[b - 1].push_back(a - 1);
    }

    vector<int> visited(vertexCount);
    vector<set<int>> bosses(vertexCount);
    for (int v = 0; v < vertexCount; v++)
        if (!visited[v])
            dfs(graph, v, visited, bosses);

    vector<int> index(vertexCount);
    for (int i = 0; i < vertexCount; i++)
        index[i] = i;

    for (int i = 0; i < queryCount; i++) {
        char type;
        cin >> type;

        if (type == 'T') {
            int a, b;
            cin >> a >> b;
            a--;
            b--;

            swap(age[index[a]], age[index[b]]);
            swap(index[a], index[b]);
        } else {
            int v;
            cin >> v;
            v = index[v - 1];

            int res = 1e9;
            for (int boss : bosses[v])
                res = min(res, age[boss]);

            if (res != 1e9)
                cout << res << "\n";
            else
                cout << "*\n";
        }
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}