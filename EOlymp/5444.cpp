#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool dfs(vector<vector<pair<int, int>>> &graphA, int vFromA, vector<int> &visited, int i, vector<pair<int, int>> &pairFromA) {
    visited[vFromA] = i;

    for (auto &[vFromB, edgeIndex] : graphA[vFromA]) {
        auto &[toFromA, toEdgeIndex] = pairFromA[vFromB];

        if (toFromA == -1 || visited[toFromA] != i && dfs(graphA, toFromA, visited, i, pairFromA)) {
            toFromA = vFromA;
            toEdgeIndex = edgeIndex;
            return 1;
        }
    }

    return 0;
}

vector<pair<int, int>> kuhn(vector<vector<pair<int, int>>> &graphA, int vertexCountB) {
    vector<int> visited(graphA.size(), -1);
    vector<pair<int, int>> pairFromA(vertexCountB, { -1, -1 });

    for (int vFromA = 0; vFromA < graphA.size(); vFromA++)
        dfs(graphA, vFromA, visited, vFromA, pairFromA);

    return pairFromA;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCountA, vertexCountB, edgeCount;
    cin >> vertexCountA >> vertexCountB >> edgeCount;

    vector<vector<pair<int, int>>> graphA(vertexCountA);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;

        graphA[a - 1].push_back({ b - 1, i });
    }

    vector<pair<int, int>> pairFromA = kuhn(graphA, vertexCountB);

    cout << vertexCountB - count(pairFromA.begin(), pairFromA.end(), make_pair(-1, -1)) << "\n";
    for (int b = 0; b < vertexCountB; b++)
        if (pairFromA[b].second != -1)
            cout << pairFromA[b].second + 1 << " ";
}