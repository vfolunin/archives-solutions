#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> readInts() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> res;
    int x;
    while (ss >> x)
        res.push_back(x);
    return res;
}

void dfs(vector<vector<int>> &graph, int v, int p, vector<vector<int>> &d) {
    d[v].resize(10);
    for (int color = 1; color < 10; color++)
        d[v][color] = color;

    for (int to : graph[v]) {
        if (to == p)
            continue;

        dfs(graph, to, v, d);

        for (int color = 1; color < 10; color++) {
            int minToColor = 0;
            for (int toColor = 1; toColor < 10; toColor++) {
                if (toColor == color)
                    continue;
                if (!minToColor || d[to][toColor] < d[to][minToColor])
                    minToColor = toColor;
            }
            d[v][color] += d[to][minToColor];
        }
    }
}

bool solve() {
    int vertexCount;
    cin >> vertexCount;

    if (!vertexCount)
        return 0;

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < vertexCount; i++) {
        int v;
        cin >> v;
        cin.ignore();
        
        vector<int> neighbors = readInts();
        for (int to : neighbors) {
            graph[v].push_back(to);
            graph[to].push_back(v);
        }
    }

    vector<vector<int>> d(vertexCount);
    dfs(graph, 0, -1, d);

    cout << max(1, *min_element(d[0].begin() + 1, d[0].end())) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}