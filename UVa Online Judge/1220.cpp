#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getId(map<string, int> &vertexId, string &name) {
    if (!vertexId.count(name))
        vertexId[name] = vertexId.size();
    return vertexId[name];
}

pair<pair<int, bool>, pair<int, bool>> dfs(vector<vector<int>> &graph, int v, int p) {
    int r0 = 0, r1 = 1;
    bool m0 = 0, m1 = 0;

    for (int to : graph[v]) {
        if (to == p)
            continue;

        auto [p0, p1] = dfs(graph, to, v);

        if (p0.first > p1.first) {
            r0 += p0.first;
            m0 |= p0.second;
        } else if (p0.first < p1.first) {
            r0 += p1.first;
            m0 |= p1.second;
        } else {
            r0 += p0.first;
            m0 |= 1;
        }

        r1 += p0.first;
        m1 |= p0.second;
    }

    return { {r0, m0}, {r1, m1} };
}

bool solve() {
    int vertexCount;
    cin >> vertexCount;

    if (!vertexCount)
        return 0;

    map<string, int> vertexId;
    string s;
    cin >> s;
    int root = getId(vertexId, s);

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < vertexCount - 1; i++) {
        string sa, sb;
        cin >> sa >> sb;

        int a = getId(vertexId, sa);
        int b = getId(vertexId, sb);

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    auto [p0, p1] = dfs(graph, root, -1);
    int r;
    bool m;
    if (p0.first > p1.first) {
        r = p0.first;
        m = p0.second;
    } else if (p0.first < p1.first) {
        r = p1.first;
        m = p1.second;
    } else {
        r = p0.first;
        m = 1;
    }

    cout << r << " " << (m ? "No" : "Yes") << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}